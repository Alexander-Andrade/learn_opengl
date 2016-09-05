#ifndef POINT_H
#define POINT_H

#include <GL\glut.h>
#include "Shape.h"
#include "PointPainter.h"
#include <cmath>
#include <iostream>

using namespace std;

struct Point : public Shape{

	GLfloat x;
	GLfloat y;
	GLfloat z;

	Point(GLfloat x, GLfloat y, GLfloat z);
	Point(const Point& p);
	Point operator+(const Point& p);
	Point operator-(const Point& p);
	Point operator*(const Point& p);
	Point operator/(const Point& p);

	double length();
	double distance_to(const Point& p);
	friend ostream& operator << (ostream& s, Point& p);
};


#endif
