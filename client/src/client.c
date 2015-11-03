/**
 * @file client.c
 * @brief client header
 * client prototypes
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#include "cdefines.h"
#include "client.h"
#include "cnet.h"
#include "csensors.h"
#include "cxml.h"

#ifdef TEST
#include "test.h"
#endif

int main(int argc, char **argv)
{
  srand (time(NULL));

  // generic declarations
  char    sendline[MAX_MSG_LEN];
  char recvline[MAX_MSG_LEN];
  int error_status = 0;

  // linux - addr declarations
  int socket_desc;
  struct sockaddr_in server_addr;

  // init
  bzero(&server_addr, sizeof server_addr);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SRV_PORT);
  inet_pton(AF_INET, SRV_ADDR, &(server_addr.sin_addr));

  while(1)
  {
    bzero(recvline, sizeof recvline);
    bzero(sendline, sizeof sendline);
    sleep(5);

    socket_desc = socket(AF_INET, PROTOCOL_TYPE, 0);
    if((error_status = connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr))) == -1)
    {
      perror("ERROR failed to connect to server");
      //close(socket_desc);
      continue;
    }

    // generate Measurements
    if((error_status = generateMeasurements()))
    {
      perror("ERROR failed to generateMeasurements");
      //close(socket_desc);
      continue;
    }

    // build request
    if((error_status = buildRequestXML(update, sendline)))
    {
      perror("ERROR: failed to connect to buildRequestXML");
      //close(socket_desc);
      continue;
    }

    // send
    if((error_status = writeSocket(socket_desc, sendline)) == -1)
    {
      perror("ERROR: failed to write to socket");
      //close(socket_desc);
      continue;
    }

    // read
    if((error_status = readSocket(socket_desc, recvline)) == -1)
    {
      perror("ERROR: failed to read from socket");
      //close(socket_desc);
      continue;
    }

    close(socket_desc);
  }
}
