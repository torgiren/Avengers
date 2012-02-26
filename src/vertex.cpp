#include "vertex.h"
Vertex& Vertex::operator+=(const Vertex& vert)
{
	int x;
	for(x=0;x<3;x++)
	{
		itsPos[x]+=vert.itsPos[x];
	};
	return *this;
};
Vertex& Vertex::operator-=(const Vertex& vert)
{
	int x;
	for(x=0;x<3;x++)
	{
		itsPos[x]-=vert.itsPos[x];
	};
	return *this;
};
