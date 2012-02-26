#ifndef __GRAPHENGINE_H
#define __GRAPHENGINE_H
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <utility>
#include "exceptions.h"
class GraphEngine
{
public:
	static GraphEngine* GetInstance();
	bool Reconfig();

	void SetResolution(int width, int height);
	void SetFullscreen(int full=-1);
	void SetViewport(int x,int y, int width, int height);
private:
	GraphEngine() throw(graph_init_error);
	int itsResolution[2];
	bool itsFullscreen;
	int itsViewport[4];
	SDL_Surface* itsScreen;
};
#endif
