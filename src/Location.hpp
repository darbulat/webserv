#ifndef LOCATION_H
# define LOCATION_H

# include <string>
# include <vector>
# include <HTTPMethod.hpp>

typedef struct s_location {
	std::string	path;
	int			allowed_methods; //OR'ing macros, eg: HTTP_GET | HTTP_POST means these 2 are allowed
	std::string	root;
	std::string	index;
	bool		autoindex;
	std::string	cgi_pass; //path to cgi or empty
} Location;

#endif //LOCATION_H
