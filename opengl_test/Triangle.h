#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL\glut.h>
#include "Shape.h"
#include "Point.h"
#include "TrianglePainter.h"

struct Triangle : public Shape{
	Point p1;
	Point p2;
	Point p3;

	Triangle(Point& p1, Point& p2, Point& p3);
	Triangle(const Triangle& Triangle);
	Triangle& operator=(const Triangle& Triangle);
	void copy(const Triangle& l);
};

#endif