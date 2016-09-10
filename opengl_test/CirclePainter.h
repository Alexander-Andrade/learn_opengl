#ifndef CIRCLE_PAINTER_H
#define CIRCLE_PAINTER_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <GL\glut.h>
#include "Circle.h"
#include "Painter.h"

struct Circle;

class CirclePainter : public Painter{
private:
	Circle* pCircle;
public:
	CirclePainter(Circle* pCircle);
	void draw() override;
	CirclePainter* newInstance(Shape* shape) override;
};


class CircleFromTriangles : public Painter {
private:
	Circle* pCircle;
public:
	CircleFromTriangles(Circle* pCircle);
	void draw() override;
	CircleFromTriangles* newInstance(Shape* shape) override;
	double getTwicePiDivAccuracy(int accuracy);
};

#endif // !1