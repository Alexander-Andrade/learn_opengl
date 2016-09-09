#include "PointPainter.h"

PointPainter::PointPainter(Point * pPoint){
	this->pPoint = pPoint;
}

void PointPainter::draw(){
	glBegin(GL_POINTS);
	glVertex3f(pPoint->x, pPoint->y, pPoint->z);
	glEnd();

	glFlush();	//
}

PointPainter * PointPainter::newInstance(Shape* shape){
	return new PointPainter((Point*)shape);
}



RedPointPainter::RedPointPainter(Point * pPoint){
	this->pPoint = pPoint;
}

void RedPointPainter::draw(){
	glColor3f(0.3, 0.7, 0.3);
	glBegin(GL_POINTS);
	glVertex3f(pPoint->x, pPoint->y, pPoint->z);
	glEnd();

	glFlush();	
}

RedPointPainter * RedPointPainter::newInstance(Shape * shape){
	return new RedPointPainter((Point*) shape);
}
