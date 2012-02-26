#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H
class file_open_error
{
	public:
		file_open_error(std::string path=""):
			itsPath(path) {};
		std::string itsPath;
};
#endif
