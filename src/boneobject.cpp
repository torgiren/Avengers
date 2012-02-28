#include "boneobject.h"
#include <iostream>
BoneObject::BoneObject()
{
	itsHead=new Bone();
	Bone* tmp=new Bone();
	tmp->itsRot.SetZ(45);
	tmp->itsChildren.push_back(new Bone());
	itsHead->itsChildren.push_back(tmp);
	tmp=new Bone();
	tmp->itsRot.SetZ(-90);
	itsHead->itsChildren.push_back(tmp);
};
void BoneObject::PrintBones() const
{
	PrintBone(itsHead,0);
};
void BoneObject::PrintBone(Bone* bone,int level) const
{
	std::list<Bone*>::iterator iter;
	int x;
	for(x=0;x<level;x++)
		std::cout<<" ";
	std::cout<<bone->itsRot.RetX()<<","<<bone->itsRot.RetY()<<","<<bone->itsRot.RetZ()<<std::endl;
	for(iter=bone->itsChildren.begin();iter!=bone->itsChildren.end();iter++)
	{
		PrintBone(*iter,level+1);
	};
};
