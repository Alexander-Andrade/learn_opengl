#include "PointPainter.h"

PointPainter::PointPainter(Point * pPoint){
	this->pPoint = pPoint;
}

void PointPainter::draw(){
	glBegin(GL_POINTS);
	glVertex3f(pPoint->x, pPoint->y, pPoint->z);
	glEnd();

	glFinish();	//
}
