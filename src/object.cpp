#include "object.h"
Object::Object()
{
	itsPos.SetX(2);
	itsPos.SetY(3);
	itsPos.SetZ(4);
};
const Vertex& Object::RetPos() const
{
	return itsPos;
};
