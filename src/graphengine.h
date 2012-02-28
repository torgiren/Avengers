#ifndef __GRAPHENGINE_H
#define __GRAPHENGINE_H
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <utility>
#include "exceptions.h"
#include "boneobject.h"
#include "staticobject.h"

//TODO wywalic iostream
#include <iostream>
using namespace std;
class GraphEngine
{
public:
	static GraphEngine* GetInstance();
	bool Reconfig();

	void SetResolution(int width, int height);
	void SetFullscreen(int full=-1);
	void SetViewport(int x,int y, int width, int height);
	
	template<typename T>
	void AddObject(T obj)
	{
		Drawer::GetDrawer(obj);
	};
private:
	GraphEngine() throw(graph_init_error);
	int itsResolution[2];
	bool itsFullscreen;
	int itsViewport[4];
	SDL_Surface* itsScreen;
	
	class Drawer
	{
	public:
		Drawer() {};
		static Drawer* GetDrawer(StaticObject* obj) {return new StaticDrawer(obj);};
		static Drawer* GetDrawer(BoneObject* obj) {return new BoneDrawer(obj);};
		virtual void Draw() const=0;
	private:
		
	};
	class StaticDrawer: public Drawer
	{
	public:
		StaticDrawer(StaticObject *obj)
		{
			cout<<"Static"<<endl;
		};
		void Draw() const {};
	};
	class BoneDrawer: public Drawer
	{
	public:
		BoneDrawer(BoneObject* obj)
		{
			cout<<"Bone"<<endl;
			itsObj=obj;
			Draw();
		};
		void Draw() const;
	private:
		void Draw(BoneObject::Bone* bone) const;
		BoneObject* itsObj;
	};
};
#endif
