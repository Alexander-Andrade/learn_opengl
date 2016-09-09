#include "CirclePainter.h"

CirclePainter::CirclePainter(Circle * pCircle){
	this->pCircle = pCircle;
}

void CirclePainter::draw(){
	glEnable(GL_POINT_SMOOTH);
	glPointSize(pCircle->r);
	glColor3f(0.3, 0.6, 0.1);
	glBegin(GL_POINTS);
	glVertex3f(pCircle->center.x, pCircle->center.y, pCircle->center.z);
	glEnd();
	glDisable(GL_POINT_SMOOTH);
}

CirclePainter * CirclePainter::newInstance(Shape * shape){
	return new CirclePainter((Circle*)shape);
}
