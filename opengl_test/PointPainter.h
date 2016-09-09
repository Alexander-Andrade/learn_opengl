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
	PointPainter(Point* pPoint);
	void draw() override;
	PointPainter* newInstance(Shape* shape) override;
};


class RedPointPainter : public Painter {
private:
	Point* pPoint;
public:
	RedPointPainter(Point* pPoint);
	void draw() override;
	RedPointPainter* newInstance(Shape* shape) override;
};

#endif
