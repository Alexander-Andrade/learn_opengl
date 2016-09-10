#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include "PointPainter.h"
#include <cmath>
#include <iostream>

using namespace std;

struct Point : public Shape{

	GLfloat x;
	GLfloat y;
	GLfloat z;

	Point(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.0);
	Point(const Point& p);
	Point& operator=(const Point& p);
	Point operator+(const Point& p);
	Point operator-(const Point& p);
	Point operator*(const Point& p);
	Point operator/(const Point& p);

	double distance();
	double distance_to(const Point& p);

	void copy(const Point& p);

	friend ostream& operator << (ostream& s, Point& p);
};


#endif
