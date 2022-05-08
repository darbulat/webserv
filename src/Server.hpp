#ifndef SERVER_H
# define SERVER_H

#include <string>
#include <vector>
#include <Config.hpp>
#include <Location.hpp>
#include <Connection.hpp>

class InvalidConfigEx;

class Server {
public:
	Server();
	~Server();

	void init(const std::string& file_path) throw(InvalidConfigEx);
	void up();
	void down();

	class InvalidConfigEx: public std::exception {
		virtual const char* what() const throw() {
			return "Invalid config file";
		}
	};
	

private:
	Connection			conns;
	std::vector<int>	listeners;
	Config				configs;

};

#endif //SERVER_H
