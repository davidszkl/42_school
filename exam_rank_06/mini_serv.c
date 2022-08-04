#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

typedef struct client {
	int id;
	int fd;
}	client;

//exam tests with message of length 100,002
//all global variables initialize to 0 by default
//select has a limmit of 1024 readable FDs
client clients[1024];
char buf[1000000], msg[1000000];
int sockfd, id, fd_max;
fd_set mem_s, r_s, w_s;

void fatal() {
	write(1, "Fatal error\n", 12);
	exit(1);
}

//start from the main provided in exam and trim it down to this
//it is a rumour that you need a backlog of 128, it doesn't really
//matter what the size of it is for this exam
int init_server(int port)
{
	struct sockaddr_in serv_addr;
	serv_addr.sin_family		= AF_INET;
	serv_addr.sin_addr.s_addr	= 16777343; 
	serv_addr.sin_port			= htons(port);

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||\
		 bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0 ||\
		 listen(sockfd, 128) < 0)
		fatal();
	
	return sockfd;
}

void send_all(int id_from)
{
	for (int i = 0; i < id; i++)
		if (clients[i].id != id_from && FD_ISSET(clients[i].fd, &w_s))
			send(clients[i].fd, msg, strlen(msg), 0);
	bzero(msg, sizeof(msg));
}

//find first empty slot in clients[] and add new client
//fd_max only increments if a client didn't leave in the meantime
void add_client()
{
	int i = 0;
	while (clients[i].fd > 0 && i < 1024)
		i++;
	struct sockaddr_in client_addr;
	socklen_t len;
	if ((clients[i].fd = accept(sockfd, (struct sockaddr*)&client_addr, &len)) < 0)
		fatal();
	FD_SET(clients[i].fd, &mem_s);
	clients[i].id = id++;
	if (clients[i].fd > fd_max)
		fd_max = clients[i].fd;
	sprintf(msg, "server: client %d just arrived\n", clients[i].id);
	send_all(clients[i].id);
}

//add multi-line message line-by-line to msg[]
//tmp[] needs to be initialized cause not global
//depending on if client sends a '\n' at the end
//of final line (multi-line case), add or don't add a '\n' to msg[]
void send_msg(int id_from)
{
	int i = 0, j = 0;
	int len = strlen(buf);
	char tmp[100000] = {0};
	while (i < len)
	{
		tmp[j++] = buf[i];
		if (buf[i++] == '\n')
		{
			sprintf(msg + strlen(msg), "client %d: %s", id_from, tmp);
			bzero(tmp, sizeof(tmp));
			j = 0;
		}
	}
	//add or don't add the '\n' here
	send_all(id_from);
}

//mem_s (memore_set) is required because select will modify
//read and write sets everytime, so you need to remember the
//clients fd's in a set that doesn't get modified
int main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "Wrong number of arguments\n", 26) && 1);

	fd_max = sockfd = init_server(atoi(argv[1]));
	FD_ZERO(&mem_s);
	FD_SET(sockfd, &mem_s);

	while (1)
	{
		r_s = w_s = mem_s;
		if (select(fd_max + 1, &r_s, &w_s, NULL, NULL) < 0)
			fatal();
		//new client wants to connect
		if (FD_ISSET(sockfd, &r_s))
			add_client();
		//check if a client sent something
		for (int i = 0; i < id; i++)
		{
			//if fd invalid or not set in read go to next client
			if (clients[i].fd < sockfd || !FD_ISSET(clients[i].fd, &r_s))
				continue ;
			//it is a rumour that you need to recv(1), my friend passed with a
			//recv of 5, if it doesn't pass there is probably an error elsewhere
			int rval = 1;
			bzero(buf, sizeof(buf));
			while (rval == 1)
			{
				rval = recv(clients[i].fd, buf + strlen(buf), 1, 0);
				if (buf[strlen(buf) - 1] == '\n')
					break;
			}
			//a correct read_loop would look like this:
			//int rval = 1000;
			//while (rval == 1000)
			//	recv = recv(clients[i].fd, buf + len, 1000, 0);

			//client sent empty send() at start of line so he exits
			if (rval == 0)
			{
				sprintf(msg, "server: client %d just left\n", clients[i].id);
				send_all(clients[i].id);
				close(clients[i].fd);
				FD_CLR(clients[i].fd, &mem_s);
				clients[i].id = -1;
				clients[i].fd = -1;
			}
			//client sent a message
			else if (rval)
				send_msg(clients[i].id);
		}
	}
}
