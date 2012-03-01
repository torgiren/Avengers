#include "graphengine.h"
#include "GL/glu.h"
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
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	float ratio=(float)itsResolution[0]/(float)itsResolution[1];
	gluPerspective( 60.0, ratio, 1.0, 1024.0 );
//	glOrtho(0.0f, itsResolution[0], itsResolution[1], 0.0f, -1.0f, 1.0f);
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
void GraphEngine::BoneDrawer::Draw() const
{
	Draw(itsObj->itsHead);		
	itsObj->PrintBones();
};
void GraphEngine::BoneDrawer::Draw(BoneObject::Bone* bone) const
{
	glPushMatrix();
//	glTranslatef(0,bone->itsDl,0);
	glRotatef(bone->itsRot.RetX(),1,0,0);
	glRotatef(bone->itsRot.RetZ(),0,0,1);
	glRotatef(bone->itsRot.RetY(),0,1,0);
//	glTranslatef(0,bone->itsDl/2,0);
	glBegin( GL_QUADS );
		glVertex3f( -0.02f, 0.f, 0.0f );
		glVertex3f( 0.02f, 0.f, 0.f );
		glVertex3f( 0.02f, bone->itsDl, 0.f );
		glVertex3f( -0.02f, bone->itsDl, 0.f );
	glEnd();
	std::list<BoneObject::Bone*>::iterator iter;
	glTranslatef(0,bone->itsDl,0);
	for(iter=bone->itsChildren.begin();iter!=bone->itsChildren.end();iter++)
	{
		Draw(*iter);
	};
	glPopMatrix();
};
