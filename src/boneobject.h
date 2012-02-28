#ifndef __BONEOBJECT_H
#define __BONEOBJECT_H
#include "object.h"
#include <list>
#include "vertex.h"
class GraphEngine;
class BoneObject: public Object
{
	friend class GraphEngine;
	class Bone
	{
	public:
		friend class GraphEngine;
		Bone() {itsRot.Set(0,0,0);itsDl=1;};
		Vertex itsRot;
		float itsDl;
		std::list<Bone*> itsChildren;
		Mesh* itsMesh;
	};
public:
	BoneObject();
	void PrintBones() const;
private:
	void PrintBone(Bone* bone,int level) const;
	Bone* itsHead;
};
#endif
