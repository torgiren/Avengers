#include "graphengine.h"
GraphEngine::GraphEngine() throw(graph_init_error):
	itsFullscreen(false),
	itsScreen(false)
{
	itsResolution[0]=800;
	itsResolution[1]=600;
	if(SDL_Init(SDL_INIT_VIDEO)!= 0)
	{
	    throw graph_init_error();
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SetViewport(0,0,itsResolution[0],itsResolution[1]);
	glEnable( GL_TEXTURE_2D );
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
	itsScreen=SDL_SetVideoMode(itsResolution[0],itsResolution[1],16,flags);
	glViewport( itsViewport[0],itsViewport[1],itsViewport[2],itsViewport[3]);
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glEnable(GL_DEPTH_TEST);
	//TODO Ulepszyć obsługę glOthod
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0.0f, itsResolution[0], itsResolution[1], 0.0f, -1.0f, 1.0f);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	return true;
};
void GraphEngine::SetFullscreen(int full)
{
	if(full==-1)
		itsFullscreen=!itsFullscreen;	
	else
		itsFullscreen=full;
};
void GraphEngine::SetResolution(int width, int height)
{
	itsResolution[0]=width;
	itsResolution[1]=height;
};
void GraphEngine::SetViewport(int x, int y, int width, int height)
{
	itsViewport[0]=x;
	itsViewport[1]=y;
	itsViewport[2]=width;
	itsViewport[3]=height;	
};
