#include "graphengine.h"
GraphEngine::GraphEngine() throw(graph_init_error):
	itsResolution(std::pair<int,int>(800,600)),
	itsFullscreen(false),
	itsScreen(false)
{
	if(SDL_Init(SDL_INIT_VIDEO)!= 0)
	{
	    throw graph_init_error();
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
};
GraphEngine* GraphEngine::GetInstance()
{
	static GraphEngine* base=new GraphEngine;
	return base;
};
bool GraphEngine::Reconfig()
{
    if(itsScreen)
		SDL_FreeSurface(itsScreen);
	Uint32 flags=SDL_OPENGL;
	if(itsFullscreen)
		flags|=SDL_FULLSCREEN;
	itsScreen=SDL_SetVideoMode(itsResolution.first,itsResolution.second,16,flags);
};
void GraphEngine::SetFullscreen(int full)
{
	if(full=-1)
	{
		itsFullscreen=!itsFullscreen;	
	}
	else
	{	
		itsFullscreen=full;
	};
};
