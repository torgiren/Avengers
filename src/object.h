#ifndef __OBJECT_H
#define __OBJECT_H
#include <vector>
#include "vertex.h"
class Object
{
protected:
	class Mesh
	{

	};
public:
	Object();
	const Vertex& RetPos() const;
	virtual std::vector<Vertex> RetVertexes() const =0;
private:
protected:
	Vertex itsPos;
	Vertex itsRot;
};
#endif
