#ifndef Painter_H
#define Painter_H
#include "Shape.h"

class Shape;

class Painter
{
public:
	virtual void draw()=0;
	virtual Painter* newInstance(Shape* shape)=0;
};

#endif // !1