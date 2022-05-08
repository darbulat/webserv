#ifndef CONFIG_H
# define CONFIG_H

# include <string>
# include <map>
# include <Location.hpp>

typedef struct s_config {
	std::string					server_name;
	stuct sockaddr_in			sockaddr; //inet_addr
	std::map<int, std::string>	error_pages; //map{status_code:path_to_page}
	std::vector<Location>		locations;
} Config;

#endif //CONFIG_H
