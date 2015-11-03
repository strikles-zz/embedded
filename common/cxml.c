/**
 * @file xml.c
 * @brief xml
 * xml parsing helpers
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */

#include <ezxml.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdefines.h"
#include "csensors.h"
#include "cxml.h"

extern volatile Reading_t readings[max_sensors];

/**
 * Build Server reply XML
 */
uint16_t buildReplyXML(char recvline[], char sendline[], size_t read_size)
{
  int sensor_ndx = 0, xml_size = 0;
  int invalid_status = 0, found_sensor = 0;
  char *sensor_name, *sensor_value, *status_xml, *req_type;
  ezxml_t reply_root, request_root, sensor;

  // check valid request xml
  if(!(request_root = ezxml_parse_str(recvline, read_size)))
  {
    perror("Invalid Request XML");
    return 1;
  }

  // check valid reply xml
  if(!(reply_root = ezxml_new("status")))
  {
    perror("Invalid Reply root XML");
    return 1;
  }
  req_type = ezxml_name(request_root);

  for(sensor = request_root->child; sensor; sensor = sensor->next)
  {
    found_sensor = 0;
    sensor_name = ezxml_name(sensor);
    for(sensor_ndx = 0; sensor_ndx < max_sensors; ++sensor_ndx)
    {
      //found our match
      if(0 == strncmp(sensor_str[sensor_ndx], sensor_name, strlen(sensor_name)))
      {
        // update value
        sensor_value = ezxml_txt(sensor);
        if(0 == strncmp(req_type, "update", strlen("update")))
        {
          readings[sensor_ndx].value = atoi(sensor_value);
        }

        // add tag
        ezxml_t child_tag = ezxml_add_child_d(reply_root, sensor_name, 4);
        ezxml_set_txt(child_tag, sensor_value);

        found_sensor = 1;

        break;
      }
    }

    if(!found_sensor)
    {
      printf("Property does not exist: %s\n", sensor_name);
      invalid_status = 1;
      break;
    }
  }

  // if we got this far the request is valid and all properties are matched
  if(!invalid_status)
  {
    // check valid reply xml
    if(!(status_xml = ezxml_toxml(reply_root)))
    {
      perror("Invalid Reply XML");
      invalid_status = 1;
    }
  }

  // msg length
  if(!invalid_status)
  {
    xml_size = strlen(status_xml) + 1;
    if(MAX_MSG_LEN < xml_size)
    {
      invalid_status = 1;
    }
  }

  // prepare sendline
  if(!invalid_status)
  {
    printf("XML: %s\n", status_xml);
    memcpy(sendline, status_xml, xml_size);
  }

  // cleanup
  free(status_xml);
  ezxml_free(reply_root);
  ezxml_free(request_root);

  return invalid_status;
}

/**
 * builds a client xml request (update/retrieve)
 */
uint16_t buildRequestXML(eRequest req, char sendline[])
{
  int xml_size = 0;
  char reading_buffer[255], *xml;
  uint16_t ndx = 0, invalid_status = 0;

  ezxml_t request_root, child_tag;
  if(!(request_root = ezxml_new(request_str[req])))
  {
    perror("Invalid request_root xml");
    return 1;
  }

  // generate some random stuff
  for(ndx = 0; ndx < max_sensors; ndx++)
  {
    // nothing to read
    if((req != configure)
        && (readings[ndx].elapsed < readings[ndx].interval))
    {
      continue;
    }

    // reset sensor buffer + copy measurement value there
    bzero(reading_buffer, 255);
    if((invalid_status = getSensorReadingStr(ndx, reading_buffer)))
    {
      perror("Error: getSensorReadingStr");
      invalid_status = 1;
      continue;
    }

    // Insert child_tag into root_tag
    if(!(child_tag = ezxml_add_child_d(request_root, sensor_str[ndx], 4)))
    {
      perror("Error: ezxml_add_child_d");
      invalid_status = 1;
      continue;
    }

    // set the tag content
    ezxml_set_txt_d(child_tag, reading_buffer);
  }

  if(!invalid_status)
  {
    if(!(xml = ezxml_toxml(request_root)))
    {
      perror("client generated Invalid xml");
      invalid_status = 1;
    }
  }

  // check max length
  if(!invalid_status)
  {
    xml_size = strlen(xml) + 1;
    if(MAX_MSG_LEN < xml_size)
    {
      perror("client xml is too long");
      invalid_status = 1;
    }
  }

  //
  if(!invalid_status)
  {
    // get string into buffer
    bzero(sendline, MAX_MSG_LEN);
    memcpy(sendline, xml, xml_size);
  }

  // free stuff
  ezxml_free(request_root);
  free(xml);

  return invalid_status;
}

/**
 * Save readings to file
 */
int writeConfig()
{
  int invalid_status = 0;
  FILE *fp;
  char config_buffer[MAX_MSG_LEN];
  bzero(config_buffer, MAX_MSG_LEN);

  if((invalid_status = buildRequestXML(configure, config_buffer)))
  {
    perror("ERROR: Failed to build config XML");
    return 1;
  }

  if((fp = fopen("configuration.xml", "w")) == NULL)
  {
    puts("Cannot open file");
    return 1;
  }

  fprintf(fp, "%s", config_buffer);
  fclose(fp);

  return 0;
}

/**
 * Load Reading from file
 */
int readConfig()
{
  ezxml_t config_root, sensor;
  int found_sensor = 0, sensor_ndx = 0, invalid_status = 0;
  char* sensor_name, *sensor_value;

  if(!(config_root = ezxml_parse_file("configuration.xml")))
  {
    perror("Failed to parse config file");
    return 1;
  }

  for(sensor = config_root->child; sensor; sensor = sensor->next)
  {
    found_sensor = 0;
    sensor_name = ezxml_name(sensor);
    for(sensor_ndx = 0; sensor_ndx < max_sensors; ++sensor_ndx)
    {
      //found our match
      if(0 == strncmp(sensor_str[sensor_ndx], sensor_name,
          strlen(sensor_name)))
      {
        // update value
        sensor_value = ezxml_txt(sensor);
        readings[sensor_ndx].value = atoi(sensor_value);
        found_sensor = 1;

        break;
      }
    }

    if(!found_sensor)
    {
      printf("Property does not exist: %s\n", sensor_name);
      invalid_status = 1;

      break;
    }
  }

  return invalid_status;
}
