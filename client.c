#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 100
#define MAX 1024

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int sock=0, valread;
	struct sockaddr_in serv_addr;
	char buffer[MAX] = {0}, input[MAX] = {0};
	if (argc > 1)
		printf(argv[1]);
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("error 1:");
		exit(EXIT_FAILURE);
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=0)
	{
		perror("error 2:");
		exit(EXIT_FAILURE);
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <0)
	{
		perror("error 3:");
		exit(EXIT_FAILURE);
	}
	while(strncmp(input, "exit", 4) != 0)
	{
		
		memset(&input, 0, sizeof(input));
		recv(sock, buffer, sizeof(buffer), 0);
		printf("%s\n", buffer);
		fgets(input, sizeof(input), stdin);
		memset(&buffer, 0, sizeof(buffer));
		write(sock, input, sizeof(input));
	}
	close(sock);
	exit(EXIT_SUCCESS);
}
		
	
