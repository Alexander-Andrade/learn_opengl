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

	Point(GLfloat x, GLfloat y) {
		painter.reset(new PointPainter(this));
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Point(const Point& p) {
		x = p.x;
		y = p.y;
		z = p.z;
	}
	
	Point operator+(const Point& p) {
		return Point(x + p.x, y + p.y, z + p.z);
	}

	Point operator-(const Point& p) {
		return Point(x - p.x, y - p.y, z - p.z);
	}

	Point operator*(const Point& p) {
		return Point(x * p.x, y * p.y, z * p.z);
	}

	Point operator/(const Point& p) {
		return Point(x / p.x, y / p.y, z / p.z);
	}

	double length() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	double distance_to(const Point& p) {
		return ((*this) - p).length();
	}

	friend ostream& operator << (ostream& s, Point& p) {
		s << "Point(" << p.x << ", " << p.y << ", "<< p.z <<")";
		return s;
	}
};


#endif
