#ifndef CIRLCE_PAINTER_H
#define CIRLCE_PAINTER_H

#include <GL/glut.h>
#include "Shape.h"
#include "Point.h"
#include "CirclePainter.h"

struct Circle : public Shape{

	Point center;
	GLfloat r;

	Circle(Point& center,GLfloat r);
	Circle(const Circle& Circle);
	Circle& operator=(const Circle& Circle);
	void copy(const Circle& l);
};

#endif // 