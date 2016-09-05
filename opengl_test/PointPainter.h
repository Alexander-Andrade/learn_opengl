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
	void draw() override;
};


#endif
