#ifndef __GRAPHENGINE_H
#define __GRAPHENGINE_H
#include <SDL/SDL.h>
#include <utility>
#include "exceptions.h"
/**
 * Klasa silnika graficznego
 */
class GraphEngine
{
public:
	static GraphEngine* GetInstance();
	void SetResolution(int width, int heigth);
	void SetResolution(std::pair<int,int> res);
	void SetFullscreen(int full=-1);
	bool Reconfig();
private:
	GraphEngine() throw(graph_init_error);
	std::pair<int,int> itsResolution;
	bool itsFullscreen;
	SDL_Surface* itsScreen;
};
#endif
