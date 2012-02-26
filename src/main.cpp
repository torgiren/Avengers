#include <iostream>
#include <stdio.h>
#include <SDL/SDL.h>
#include "graphengine.h"
#include "loader.h"
using std::cout;
using std::endl;
int main()
{
	GraphEngine *graph=GraphEngine::GetInstance();
	graph->Reconfig();
	SDL_Delay(3000);
	graph->SetResolution(1280,768);
	graph->Reconfig();
	SDL_Delay(3000);
	return 0;
};
