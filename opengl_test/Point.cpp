#include "Point.h"

Point::Point(GLfloat x, GLfloat y, GLfloat z) : Shape(new PointPainter(this)){
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(const Point & p) : Shape(nullptr){
	copy(p);
}

Point & Point::operator=(const Point & p){
	copy(p);
	return *this;
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

double Point::distance(){
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Point::distance_to(const Point & p){
	return ((*this) - p).distance();
}

void Point::copy(const Point& p){
	copyPainter(p.painter.get());
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

ostream & operator<<(ostream & s, Point & p){
	s << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
	return s;
}
