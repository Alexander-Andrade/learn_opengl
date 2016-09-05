#include "PointPainter.h"

void PointPainter::draw(){
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(pPoint->x, pPoint->y, pPoint->z);
	glEnd();

	glFlush();	//
}
