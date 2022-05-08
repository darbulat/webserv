#ifndef CONNECTION_H
# define CONNECTION_H

# include <Config.hpp>

typedef struct s_connection {
	int					fd;
	std::vector<char>	buffer;
	// Response			resp;
	Config				*conf;
} Connection;

#endif CONNECTION_H
