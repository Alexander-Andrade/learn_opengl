#ifndef Line_H
#define Line_H
#include <GL/glut.h>
#include "Shape.h"
#include "Point.h"

struct Line : public Shape {
	Point p1;
	Point p2;

	Line(Point& p1, Point& p2);
	Line(const Line& line);
	Line& operator=(const Line& line);
	void copy(const Line& l);
};

#endif
