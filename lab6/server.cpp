#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "coder.h"

#define BUFFERMAX 100

void handleConnection(int FDSocketConnection);

int main(int argc, char **argv)
{
	int FDSocketConnection, connfd, len;
	struct sockaddr_in servaddr, cli;

	if (argc <= 1) {
		printf("Usage: server PORT\n");
		return 1;
	}
	FDSocketConnection = socket(AF_INET, SOCK_STREAM, 0);
	if (FDSocketConnection == -1)
	{
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
	{
		printf("Socket successfully created..\n");
	}
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	int	bindingResult = bind(FDSocketConnection, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (bindingResult != 0)
	{
		printf("Socket bind failed...\n");
		exit(0);
	}
	else
	{
		printf("Socket binded..\n");
	}

	int serverListeningResult = listen(FDSocketConnection, 5);
	if (serverListeningResult != 0)
	{
		printf("Server's listening failed...\n");
		exit(0);
	}
	else
	{
		printf("Server's listening now..\n");
	}

	len = sizeof(cli);

	FDSocketConnection = accept(FDSocketConnection, (struct sockaddr *)&cli, (socklen_t *)&len);
	if (FDSocketConnection < 0)
	{
		printf("Client connection failed...\n");
		exit(0);
	}
	else
	{
		printf("Client connected...\n");
	}

	handleConnection(FDSocketConnection);

	close(FDSocketConnection);
}

void handleConnection(int FDSocketConnection)
{
	char buffer[BUFFERMAX];
	int n;
	while (1)
	{
		//set buffer to zero
		bzero(buffer, BUFFERMAX);

		read(FDSocketConnection, buffer, sizeof(buffer));
		printf("Converting to morse - %s", buffer);
		std::string encoded = encode(std::string(buffer));
		sleep(2);
		write(FDSocketConnection, encoded.c_str(), sizeof(encoded.c_str()));
		if (strncmp("exit", buffer, 4) == 0)
		{
			printf("Connection closed...\n");
			break;
		}
	}
}