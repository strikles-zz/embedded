/**
 * @file xml.h
 * @brief xml
 * xml parsing helpers
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */

#ifndef XML_H_
#define XML_H_

#include <stddef.h>
#include <stdint.h>

#include "cdefines.h"

/**
 * Builds XML
 * @param recvline
 * @param sendline
 * @param read_size
 * @return invalid_status
 */
uint16_t buildReplyXML(char recvline[], char sendline[], size_t read_size);

/**
 * builds a client xml request (update/retrieve)
 * @param req
 * @param sendline
 * @return invalid_status
 */
uint16_t buildRequestXML(eRequest req, char sendline[]);

/**
 * Save readings to file
 * @return invalid_status
 */
int writeConfig();

/**
 * Load Reading from file
 * @return invalid_status
 */
int readConfig();

#endif /* XML_H_ */
