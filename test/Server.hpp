

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
	locations
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
	startup
	shutdown
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
