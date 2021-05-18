#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#define MAX 1024
#define PORT 100
#define USER "adam"
#define PASS "pass"

void func(int sock, char *buffer, char** envp)
{
	
	int pip[2];
	
	int i=0;
	write(sock, "Enter command", 13);
	recv(sock, buffer, sizeof(buffer), 0);
	strtok(buffer, "\n");
	
	//strcpy((char*) command, buffer);
	//char* command[]={buffer, (char*)0};
	char command[50];
	strcpy(command, "/bin/");
	strcat(command, buffer);
	printf("%s\n",command);
	char* arg[]={command, "./", NULL};
	
	
		/*strtok(command, "\n");
		strcat(command, " > results.txt");
		system(command);
		FILE *fpointer;
		fpointer = fopen("results.txt", "r");
		while ((c = fgetc(fpointer)) != EOF)
		{
			buffer[i] = c;
			i++;
		}
		fclose(fpointer);
		printf("%s\n", buffer);
		write(sock, buffer, sizeof(buffer));*/
	if (pipe(pip)==-1){
		perror("pipe1 error:");
		exit(EXIT_FAILURE);
	}
	
	pid_t p = fork();
	if (p < 0)
	{
		perror("fork error:");
		exit(EXIT_FAILURE);
	}
	else if(p > 0)
	{
		close(pip[0]);
		read(pip[1], buffer, sizeof(buffer));
		wait(NULL);
		printf(buffer);
		write(sock, buffer, sizeof(buffer));

	}
	else
	{
		close(pip[1]);
		dup2(pip[0], 1);
		execve(command, arg, envp);
		perror("execve failed");
	}
		
		
	
}

void hidden()
{
	printf("haha, I'm invisible\n");
}

int main(int argc, char const *argv[], char* envp[])
{
	int serv, sock, valread, opt=1, port=PORT, user=0, pass=0;
	if(argc == 2)
		port = atoi(argv[1]);
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[MAX];
	int i = 0;
	serv = socket(AF_INET, SOCK_STREAM, 0);
	/*if ((serv = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("error 1:");
		exit(EXIT_FAILURE);
	}*/
	setsockopt(serv, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	/*if (setsockopt(serv, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("error 2:");
		exit(EXIT_FAILURE);
	}*/
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	bind(serv, (struct sockaddr *)&address, sizeof(address));
	/*if (bind(serv, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("error 4:");
		exit(EXIT_FAILURE);
	}*/
	listen(serv, 3);
	/*if (listen(serv, 3) < 0)
	{
		perror("error 5:");
		exit(EXIT_FAILURE);
	}*/
	sock = accept(serv, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	/*if ((sock = accept(serv, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
	{
		perror("error 6: ");
		exit(EXIT_FAILURE);
	}*/
	
	while(strcmp(buffer, "exit") != 0)
	{
		memset(&buffer, 0, sizeof(buffer));
		if(user == 0)
			write(sock, "Enter username", 14);
		if(user==1 && pass==0)
			write(sock, "Enter password", 14);
		recv(sock, buffer, sizeof(buffer), 0);
		printf("%s", buffer);
		if(strncmp(buffer,USER, 4) == 0)
			user=1;
		if(strncmp(buffer,PASS, 4) == 0)
			pass=1;
		if(user==1 && pass==1){
			func(sock, buffer, envp);
			close(sock);
			exit(EXIT_SUCCESS);
		}
	}
	
}
	
	

