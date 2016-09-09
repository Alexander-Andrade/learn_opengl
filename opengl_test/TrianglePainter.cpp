#include "TrianglePainter.h"

TrianglePainter::TrianglePainter(Triangle* pTriangle){
	this->pTriangle = pTriangle;
}

void TrianglePainter::draw(){
	glBegin(GL_TRIANGLES);
	glVertex3f(pTriangle->p1.x, pTriangle->p1.y, pTriangle->p1.z);
	glVertex3f(pTriangle->p2.x, pTriangle->p2.y, pTriangle->p2.z);
	glVertex3f(pTriangle->p3.x, pTriangle->p3.y, pTriangle->p3.z);
	glEnd();
}

TrianglePainter * TrianglePainter::newInstance(Shape * shape){
	return new TrianglePainter((Triangle*)shape);
}

