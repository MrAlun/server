#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include "net/warp_socket.h"


#define	MAXLINE		4096	/* max text line length */

int main( int argc, char **argv )
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;
	
	if ( argc != 3 )
		printf( "usage: a.out <IPaddress>" );

	if ( ( sockfd = Socket( AF_INET, SOCK_STREAM, 0 ) ) < 0)
		exit( -1 );

	bzero( &servaddr, sizeof servaddr );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons( atoi( argv[2] ) );
	if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr ) <= 0)
		printf( "inet_pton error for %s", argv[1] );

	if ( Connect( sockfd, (Address*) &servaddr, sizeof servaddr ) < 0)
		printf( "connect error" );

	while ( ( n = read(sockfd, recvline, MAXLINE ) ) > 0) 
	{
		recvline[n] = 0;
		if ( fputs( recvline, stdout ) == EOF )
			printf( "fputs error" );
	}
	if ( n < 0 )
		printf( "read error" );

	exit( 0 );
}