#include <iostream>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include "graphengine.h"
#include "loader.h"
#include "object.h"
#include "vertex.h"
#include "boneobject.h"
using std::cout;
using std::endl;
void bone()
{
	glBegin( GL_QUADS );
		glVertex3f( -0.02f, -0.2f, -2.0f );
		glVertex3f( 0.02f, -0.2f, -2.f );
		glVertex3f( 0.02f, 0.2f, -2.f );
		glVertex3f( -0.02f, 0.2f, -2.f );
	glEnd();
};
int main()
{
//	Loader load;
	GraphEngine *graph=GraphEngine::GetInstance();
	graph->Reconfig();
	glTranslatef(0,0,-10);
//	graph->AddObject(new StaticObject());
	graph->AddObject(new BoneObject());
	SDL_Delay(10);
/*
	int x=0;
	for(x=0;x<90;x++)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glPushMatrix();

		SDL_Delay(5);
		cout<<glGetError()<<endl;
		glLoadIdentity();
		bone();

		glTranslatef(0.0f,0.2f,0.0f);
		glRotatef(45,0,0,1.0f);
		glTranslatef(0.0f,0.2f,0.0f);

		glPushMatrix();
		
		bone();

		glTranslatef(0.0f,0.2f,0.0f);
		glRotatef(90,0,0,1.0f);
		glTranslatef(0.0f,0.2f,0.0f);
		bone();

		glPopMatrix(); 

		glTranslatef(0.0f,0.2f,0.0f);
		glRotatef(x*(-1),0,0,1.0f);
		glTranslatef(0.0f,0.2f,0.0f);
		bone();

		glPopMatrix();

		SDL_GL_SwapBuffers();
		SDL_Delay(50);
	};
 


	SDL_Delay(5);
	SDL_GL_SwapBuffers();
	SDL_Delay(2000);
//	graph->SetResolution(1028,768);	
//	graph->Reconfig();
*/
	SDL_GL_SwapBuffers();
	SDL_Delay(2000);


	printf("Koniec...\n");
	return 0;
};
