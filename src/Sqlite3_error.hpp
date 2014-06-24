#ifndef SQLITE3_ERROR_HPP
#define SQLITE3_ERROR_HPP 1

#include <stdexcept>

namespace sqlite
{

class Sqlite3_error : public std::runtime_error {
public:
	explicit Sqlite3_error(const std::string& err_msg)
		: std::runtime_error(err_msg)
	{
	}
};

}

#endif /* SQLITE3_ERROR_HPP */
