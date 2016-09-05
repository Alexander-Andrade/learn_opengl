#include "Point.h"

Point::Point(GLfloat x, GLfloat y, GLfloat z){
	painter.reset(new PointPainter(this));
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(const Point & p){
		x = p.x;
		y = p.y;
		z = p.z;
}

Point Point::operator+(const Point & p){
	return Point(x + p.x, y + p.y, z + p.z);
}

Point Point::operator-(const Point & p){
	return Point(x - p.x, y - p.y, z - p.z);
}

Point Point::operator*(const Point & p){
	return Point(x * p.x, y * p.y, z * p.z);
}

Point Point::operator/(const Point & p){
	return Point(x / p.x, y / p.y, z / p.z);
}

double Point::length(){
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Point::distance_to(const Point & p){
	return ((*this) - p).length();
}

ostream & operator<<(ostream & s, Point & p){
	s << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
	return s;
}
