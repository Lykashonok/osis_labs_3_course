#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>


#define BUFFERMAX 100

void handleConnection(int FDSocketConnection);

int main(int argc, char** argv)
{
	int FDSocketConnection, connfd;
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
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(atoi(argv[1]));

	int connectionResult = connect(FDSocketConnection, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (connectionResult != 0)
	{
		printf("Connection to server failed...\n");
		exit(0);
	}
	else
	{
		printf("Connected to server..\n");
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
		bzero(buffer, sizeof(buffer));
		printf("String to convert: ");
		n = 0;
		while ((buffer[n++] = getchar()) != '\n');
		write(FDSocketConnection, buffer, sizeof(buffer));
		bzero(buffer, sizeof(buffer));
		read(FDSocketConnection, buffer, sizeof(buffer));
		printf("Converted from server: %s\n", buffer);
		if ((strncmp(buffer, "exit", 4)) == 0)
		{
			printf("Connection closed...\n");
			break;
		}
	}
}