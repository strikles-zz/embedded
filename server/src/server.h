/**
* @file server.h
* @brief server
* server definitions
*
* @author Claudio Neto
*
* @date 3/11/2015
*/

#ifndef SERVER_H_
#define SERVER_H_

/**
 * new connection handler
 * @param socket fd
 */
void *connection_handler(void *);

/**
 * handler for service shutdown
 * @param s signal
 */
void shutdownHandler(int s);

/**
 * Unused
 */
void exitHandler();

#endif /* SERVER_H_ */
