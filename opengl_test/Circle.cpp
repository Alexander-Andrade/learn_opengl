#include "Circle.h"



Circle::Circle() : Shape(new CirclePainter(this)){
}

Circle::Circle(const Circle& circle) : Shape(nullptr){
	copy(circle);
}

Circle& Circle::operator=(const Circle & circle){
	copy(circle);
}

void Circle::copy(const Circle& circle){
	copyPainter(circle.painter.get());
	r = circle.r;
}

