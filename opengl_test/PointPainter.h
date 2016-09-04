#ifndef POINT_PAINTER_H
#define POINT_PAINTER_H

#include <GL\glut.h>
#include "Painter.h"
#include "Point.h"

using namespace std;

struct Point;

class PointPainter : public Painter {
private:
	Point* pPoint;
public:
	PointPainter(Point* pPoint) {
		this->pPoint = pPoint;
	}
	void draw() override {
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
		glEnd();

		glFlush();	//
	}
};


#endif
