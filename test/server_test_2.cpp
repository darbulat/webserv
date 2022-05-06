#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>

#define PORT 8000

int	main()
{
	/* for (int i = 0; i < 20; i++) {
		struct protoent	*proto = getprotobynumber(i);
		std::cout << i <<  " " << proto->p_name << "\n";
	} */

	int	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		std::cout << "Failed to create socket, errno " << errno << ": "
			<< strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	int opt = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int))) {
		std::cout << "Failed to set socket options, errno " << errno << ": "
			<< strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
	}
	
	struct sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(PORT);
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0) {
		std::cout << "Failed to bind port " << PORT << ", errno " << errno 
			<< ": " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	if (listen(sockfd, 10) < 0) {
		std::cout << "Failed to listen on socket, errno " << errno << ": "
			<< strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	
	struct sockaddr_in conn_addr;
	while(true) {
		socklen_t addrlen = sizeof(sockaddr);
		int conn = accept(sockfd, (struct sockaddr *)&conn_addr, &addrlen);
		if (conn < 0) {
			std::cout << "Failed to accept a connection, errno " << errno
				<< ": " << strerror(errno) << std::endl;
			continue;
		} else {
			std::cout << "Connection accepted: new fd = " << conn << std::endl;
		}
		char buffer[1024];
		// buffer[1024] = 0;
		ssize_t bytes_recvd = recv(conn, buffer, 1023, 0);
		if (bytes_recvd < 0) {
			std::cout << "Failed to read from connection " << conn << ", errno "
				<< errno << ": " << strerror(errno) << std::endl;
		} else {
			std::cout << buffer;
			std::cout << ">>> end of the message \n";
		}
		close(conn);
	}
	close(sockfd);
}
