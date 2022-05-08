struct Config
{
	server_name
	host
	port
	
	error_pages
	locations
}

struct Location {
	path
	allow_methods
	root
	index
	auto_index
	client_body
	cgi_pass
	<!-- locations -->
}

struct Connection {
	fd
	buffer
	response
	*config
}

class Server
{
	connections
	listeners
	configs

	init(pathToConfig) {
		configParser
		configs = configParser.parse(pathToConfig)
	}
	up
	down
}

class ConfigParser {
	parse(pathToFile)
}

int main() {
	server
	server.init(pathToConfig)
	server.startup()
}

fd - server 
1 - *asd

1. Non-blocking server via select able to serve multiple clients
2. Connection for keeping track of partial reads
3. Config based multiple virtual servers
4. Find locations. If found, serve, otherwise return 404
5. Check config rules for location
