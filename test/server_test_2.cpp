#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

int	main()
{
	/* for (int i = 0; i < 20; i++) {
		struct protoent	*proto = getprotobynumber(i);
		std::cout << i <<  " " << proto->p_name << "\n";
	} */

	int	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		std::cout << "Failed to create socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}
	
}
