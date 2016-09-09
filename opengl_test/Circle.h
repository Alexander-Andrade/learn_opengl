#ifndef CIRLCE_PAINTER_H
#define CIRLCE_PAINTER_H

#include "Shape.h"
#include "CirclePainter.h"

struct Circle : public Shape{

	GLfloat r;

	Circle();
	Circle(const Circle& Circle);
	Circle& operator=(const Circle& Circle);
	void copy(const Circle& l);
};

#endif // 