#include "loader.h"
#include <cstring>
Loader::Loader(std::string path) throw (file_open_error)
{
	itsFile.open(path.c_str(),std::ios::in);
	if(!itsFile.is_open())
		throw file_open_error(path);
	itsLine=new char[255];
};
Loader::~Loader()
{
	delete [] itsLine;
};
std::string Loader::GetLine()
{
//	memset(itsLine,0,255);
	char *wsk=itsLine;
	if(itsFile.eof())
		return std::string("");
	itsFile.getline(wsk,255);
	if(!strlen(wsk))
		return GetLine();
	while(wsk[0]==32||wsk[0]==9)
	{
		if(strlen(wsk)>0)
			wsk=&wsk[1];
		else
			return GetLine();
	};
	if(wsk[0]=='#')
		return GetLine();
	return wsk;
};
bool Loader::IsMore()
{
	return !itsFile.eof();
};
