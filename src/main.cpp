#include <iostream>
#include <stdio.h>
#include <SDL/SDL.h>
#include "loader.h"
using std::cout;
using std::endl;
int main()
{
	try
	{
		Loader a("config.cfg");
		do
		{
			cout<<a.GetLine()<<endl;
		}
		while(a.IsMore());
	}
	catch(file_open_error e)
	{
		cout<<"Problem z otwarciem pliku: "<<e.itsPath<<endl;
	};
/*
	if(SDL_Init(SDL_INIT_VIDEO)!= 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_Surface* screen=SDL_SetVideoMode(640, 480, 16, SDL_OPENGL );
	SDL_Delay(1000);
*/
	return 0;
};
