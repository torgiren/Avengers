#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H
#include <string>
class file_open_error
{
public:
	file_open_error(std::string path=""):
		itsPath(path) {};
	std::string itsPath;
};
class graph_init_error {};
#endif
