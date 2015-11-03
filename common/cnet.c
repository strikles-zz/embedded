/**
 * @file net.c
 * @brief networking
 * common net definitions
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "cdefines.h"
#include "cnet.h"

/**
 * Read from Socket
 */
int readSocket(int sock, char recvline[])
{
  puts("socket reading...");

  char* pBuf = recvline;
  int n = 0, bytesLeft = MAX_MSG_LEN - 1, bytesDone = 0;

  while (bytesLeft > 0)
  {
    if ((n = read(sock, pBuf, bytesLeft)) == -1)
    {
      perror("ERROR writing to socket");
      break;
    }
    if (n == 0)
    {
      puts("socket closed ?");
      break;
    }

    pBuf += n;
    bytesLeft -= n;
    bytesDone += n;
  }

  recvline[bytesDone] = '\0';
  printf("socket read complete: (%d, %d) %s\n", n, bytesLeft, recvline);

  return n;
}

/**
 * Write to socket
 */
int writeSocket(int sock, char sendline[])
{
  puts("socket writing...");

  char* pBuf = sendline;
  int n = 0, bytesLeft = MAX_MSG_LEN - 1;

  while (bytesLeft > 0)
  {
    if ((n = write(sock, pBuf, bytesLeft)) == -1)
    {
      perror("ERROR writing to socket");
      break;
    }

    pBuf += n;
    bytesLeft -= n;
  }

  printf("socket write complete: (%d, %d) %s\n", n, bytesLeft, sendline);

  return n;
}

/**
 * Connect to Sever
 */
int connectToServer(void* sock_desc)
{
  int sock = *(int*) sock_desc;
  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof server_addr);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SRV_PORT);
  inet_pton(AF_INET, SRV_ADDR, &(server_addr.sin_addr));

  int invalid_status = 0;
  if ((invalid_status = connect(sock, (struct sockaddr *) &server_addr,
      sizeof(server_addr))) == -1)
  {
    perror("ERROR failed to connect to server");
  }

  return invalid_status;
}
