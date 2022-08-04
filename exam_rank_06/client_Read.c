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
    char read_buf[100000] = {0};

	while (1)
	{
		write(1, "receiving\n", 11);
		int rval = recv(sockfd, read_buf, sizeof(read_buf), 0);
		if (!rval)
		{
			close(sockfd);
			exit(1);
		}
		printf("%s", read_buf);
		bzero(read_buf, sizeof(read_buf));
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