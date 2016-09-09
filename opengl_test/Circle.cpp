#include "Circle.h"



Circle::Circle( Point& center,GLfloat r) : Shape(new CirclePainter(this)){
	this->center = center;
	this->r = r;
}


Circle::Circle(const Circle& circle) : Shape(nullptr){
	copy(circle);
}

Circle& Circle::operator=(const Circle & circle){
	copy(circle);
	return *this;
}

void Circle::copy(const Circle& circle){
	copyPainter(circle.painter.get());
	center = circle.center;
	r = circle.r;
}

