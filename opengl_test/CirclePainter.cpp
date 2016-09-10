#include "CirclePainter.h"



CirclePainter::CirclePainter(Circle * pCircle){
	this->pCircle = pCircle;
}

void CirclePainter::draw(){
	glPushAttrib(GL_POINT_BIT);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(pCircle->r);
	glColor3f(0.3, 0.6, 0.1);
	glBegin(GL_POINTS);
	glVertex3f(pCircle->center.x, pCircle->center.y, pCircle->center.z);
	glEnd();
	glPopAttrib();
}

CirclePainter * CirclePainter::newInstance(Shape * shape){
	return new CirclePainter((Circle*)shape);
}





CircleFromTriangles::CircleFromTriangles(Circle * pCircle, int accuracy){
	this->pCircle = pCircle;
	this->accuracy = accuracy;
}

void CircleFromTriangles::draw(){
	double twicePidivAccur = getTwicePiDivAccuracy();
	double x_coord = 0.0;
	double y_coord = 0.0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(pCircle->center.x, pCircle->center.y, 0.0);
	for (int i = 0; i <= accuracy; i++) {
		x_coord = pCircle->center.x + pCircle->r*cos(i*twicePidivAccur);
		y_coord = pCircle->center.y + pCircle->r*sin(i*twicePidivAccur);
		glVertex3d(x_coord, y_coord, 0.0);
	}
	glEnd();
}

CircleFromTriangles * CircleFromTriangles::newInstance(Shape * shape){
	return new CircleFromTriangles((Circle*)shape);
}

double CircleFromTriangles::getTwicePiDivAccuracy(){
	return 2.0 * M_PI / accuracy;
}

void CircleFromTriangles::setAccuracy(int accuracy){
	this->accuracy = accuracy;
}
