#ifndef __BONEOBJECT_H
#define __BONEOBJECT_H
#include "object.h"
#include <list>
#include "vertex.h"
class BoneObject: public Object
{
	class Bone
	{
	public:
		Bone() {itsRot.Set(0,0,0);};
		Vertex itsRot;
		std::list<Bone*> itsChildren;
	};
public:
	BoneObject();
	void PrintBones() const;
	std::vector<Vertex> RetVertexes() const {return std::vector<Vertex>();};
private:
	void PrintBone(Bone* bone,int level) const;
	Bone* itsHead;
};
#endif
