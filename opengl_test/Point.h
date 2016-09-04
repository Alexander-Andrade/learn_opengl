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

	Point(GLfloat x, GLfloat y) {
		painter.reset(new PointPainter(this));
		this->x = x;
		this->y = y;
	}

	Point(const Point& p) {
		x = p.x;
		y = p.y;
	}
	
	Point operator+(const Point& p) {
		return Point(x + p.x, y + p.y);
	}

	Point operator-(const Point& p) {
		return Point(x - p.x, y - p.y);
	}

	Point operator*(const Point& p) {
		return Point(x * p.x, y * p.y);
	}

	Point operator/(const Point& p) {
		return Point(x / p.x, y / p.y);
	}

	double length() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	double distance_to(const Point& p) {
		return ((*this) - p).length();
	}

	friend ostream& operator << (ostream& s, Point& p) {
		s << "Point(" << p.x << ", " << p.y << ")";
		return s;
	}
};


#endif
