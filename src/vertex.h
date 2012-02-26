#ifndef __VERTEX_H
#define __VERTEX_H
class Vertex
{
public:
	Vertex& operator+=(const Vertex& vert);
	Vertex& operator-=(const Vertex& vert);
	inline float RetX() const {return (float)itsPos[0]/100;};
	inline float RetY() const {return (float)itsPos[1]/100;};
	inline float RetZ() const {return (float)itsPos[2]/100;};
	inline void SetX(float x) {itsPos[0]=x*100;};
	inline void SetY(float y) {itsPos[1]=y*100;};
	inline void SetZ(float z) {itsPos[2]=z*100;};
	inline void Set(float x, float y, float z) {SetX(x);SetY(y);SetZ(z);};
private:
	int itsPos[3];
};
#endif
