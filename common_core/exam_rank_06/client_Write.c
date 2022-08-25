#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <netdb.h>

void func(int sockfd)
{
	char write_buf[100000] = {0};
	while (1)
	{
		write(1, "You> ", 5);
		read(STDIN_FILENO, write_buf, 100);
		if (write_buf[0] == '\n')
		{
			close(sockfd);
			exit(1);
		}
		else
		{
			send(sockfd, write_buf, strlen(write_buf), 0);
		}
		bzero(write_buf, sizeof(write_buf));
	}
}

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		return write(STDERR_FILENO, "Fatal error\n", 13) && 1;

	struct sockaddr_in server_addr;

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family		= AF_INET;
	server_addr.sin_addr.s_addr	= inet_addr("127.0.0.1");
	server_addr.sin_port		= htons(4242);

	if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
		return write(STDERR_FILENO, "Fatal error\n", 13) && 1;
	
	func(sockfd);
	close(sockfd);
	return 0;
}