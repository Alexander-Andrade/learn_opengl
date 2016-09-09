#include "Line.h"
#include "LinePainter.h"

Line::Line(Point & p1, Point & p2) : Shape(new LinePainter(this)){
	this->p1 = p1;
	this->p2 = p2;
}

Line::Line(const Line& line) : Shape(new LinePainter(this)){
	copy(line);
}

Line& Line::operator=(const Line & line){
	copy(line);
	return *this;
}

void Line::copy(const Line & line){
	copyPainter(line.painter.get());
	this->p1 = line.p1;
	this->p2 = line.p2;
}
