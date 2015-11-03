/**
 * @file net.h
 * @brief networking
 * common net definitions
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */

#ifndef NET_H_
#define NET_H_

#define PROTOCOL_TYPE SOCK_STREAM
//#define PROTOCOL_TYPE SOCK_DGRAM

#include "cdefines.h"

/**
 *
 * @param sock
 * @param recvline
 * @return invalid_status
 */
int readSocket(int sock, char recvline[]);

/**
 *
 * @param sock
 * @param sendline
 * @return invalid_status
 */
int writeSocket(int sock, char sendline[]);

/**
 *
 * @param sock_desc
 * @return invalid_status
 */
int connectToServer(void* sock_desc);

#endif /* NET_H_ */
