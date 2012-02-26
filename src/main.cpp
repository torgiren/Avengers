#include <stdio.h>
#include <SDL/SDL.h>
int main()
{
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); // *new*

	SDL_Surface* screen = SDL_SetVideoMode( 640, 480, 16, SDL_OPENGL ); // *changed*
	SDL_Delay(1000);
	return 0;
};
