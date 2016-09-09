#include "Triangle.h"

Triangle::Triangle(Point & p1, Point & p2, Point & p3) : Shape(new TrianglePainter(this)){
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Triangle::Triangle(const Triangle& triangle) : Shape(nullptr){
	copy(triangle);
}

Triangle & Triangle::operator=(const Triangle& triangle){
	copy(triangle);
	return *this;
}



void Triangle::copy(const Triangle & triangle){
	copyPainter(triangle.painter.get());
	this->p1 = triangle.p1;
	this->p2 = triangle.p2;
	this->p3 = triangle.p3;
}


