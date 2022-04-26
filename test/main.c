#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT "8000"
#define MAX_CONNECTION 1000

int create_socket(const char *apstrPort) {
	struct addrinfo	hints;
	struct addrinfo	*servinfo;
	struct addrinfo	*p;

	memset(&hints, 0, sizeof(hints));
	// bzero(&hints, sizeof(hints));

	// IPv4 or IPv6
	hints.ai_family		= AF_UNSPEC;
	hints.ai_socktype	= SOCK_STREAM;
	hints.ai_flags		= AI_PASSIVE;

	int	r = getaddrinfo(NULL, apstrPort, &hints, &servinfo);
	if (r != 0) {
		fprintf(stderr, "error getaddrinfo\n");
		return -1;
	}

	int	sock;
	int	yes;
	for (p = servinfo; p != NULL; p = p->ai_next) {
		sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (sock == -1) {
			continue;
		}
		if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
			fprintf(stderr, "error setsockopt\n");
			close(sock);
			freeaddrinfo(servinfo);
			return -2;
		}
		if (bind(sock, p->ai_addr, p->ai_addrlen) == -1) {
			close(sock);
			continue;
		}
	}
	freeaddrinfo(servinfo);
	if (p == NULL) {
		fprintf(stderr, "failed to find address\n");
		return -3;
	}
	if (listen(sock, MAX_CONNECTION) == -1) {
		fprintf(stderr, "error listen\n");
		return -4;
	}
	return sock; 
}

int	main() {
	int	sock;

	sock = create_socket(SERVER_PORT);
	if (sock < 0) {
		fprintf(stderr, "error create_socket\n");
		return -1;
	}
	printf("server created\n");
	struct sockaddr_storrage	client;
	int							client_desc;
	while(1) {
		cliend_desc = accept(sock, (struct sockaddr *)&client, sizeof(client_addr));
		if (client_desc == -1) {
			fprintf(stderr, "error accept\n");
			return -1;
		}
	}
}
