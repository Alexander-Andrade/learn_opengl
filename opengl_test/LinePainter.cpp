#include "LinePainter.h"

LinePainter::LinePainter(Line* pPoint){
	this->pLine = pPoint;
}

void LinePainter::draw(){
	glBegin(GL_LINES);
	glVertex3f(pLine->p1.x, pLine->p1.y, pLine->p1.z);
	glVertex3f(pLine->p2.x, pLine->p2.y, pLine->p2.z);
	glEnd();
}

LinePainter * LinePainter::newInstance(Shape * shape){
	return new LinePainter((Line*)shape);
}
