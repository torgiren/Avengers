#ifndef __LOADER_H
#define __LOADER_H
#include <string>
#include <fstream>
#include "exceptions.h"
class Loader
{
public:
	Loader(std::string path) throw (file_open_error);
	~Loader();
	std::string GetLine();
	bool IsMore();
private:
	std::ifstream itsFile;
	char *itsLine;
};
#endif
