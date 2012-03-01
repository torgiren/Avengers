#include "boneobject.h"
#include <iostream>
BoneObject::BoneObject()
{
/*
	itsHead=new Bone();
	Bone* tmp=new Bone();
	tmp->itsRot.SetZ(45);
	tmp->itsChildren.push_back(new Bone());
	itsHead->itsChildren.push_back(tmp);
	tmp=new Bone();
	tmp->itsRot.SetZ(-90);
	itsHead->itsChildren.push_back(tmp);
*/
	Bone* bones=new Bone[12];
	bones[0].itsRot.Set(0,0,0);
	bones[0].itsDl=2;
	
	bones[1].itsRot.Set(0,0,-90);
	bones[2].itsRot.Set(0,0,-90);
	bones[3].itsRot.Set(0,0,-10);

	bones[4].itsRot.Set(0,0,90);
	bones[5].itsRot.Set(0,0,90);
	bones[6].itsRot.Set(0,0,10);

	bones[7].itsRot.Set(0,0,0);

	bones[8].itsRot.Set(0,0,-90);
	bones[9].itsRot.Set(0,0,-10);

	bones[10].itsRot.Set(0,0,90);
	bones[11].itsRot.Set(0,0,10);

	Bone *head=new Bone;
	head->itsDl=0.0;
	itsHead=head;
	itsHead->itsChildren.push_back(&bones[0]);
	itsHead->itsChildren.push_back(&bones[1]);
	itsHead->itsChildren.push_back(&bones[4]);
	bones[1].itsChildren.push_back(&bones[2]);
	bones[2].itsChildren.push_back(&bones[3]);
	bones[4].itsChildren.push_back(&bones[5]);
	bones[5].itsChildren.push_back(&bones[6]);
	bones[0].itsChildren.push_back(&bones[7]);
	bones[0].itsChildren.push_back(&bones[8]);
	bones[0].itsChildren.push_back(&bones[10]);
	bones[8].itsChildren.push_back(&bones[9]);
	bones[10].itsChildren.push_back(&bones[11]);

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
