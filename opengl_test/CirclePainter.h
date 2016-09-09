#ifndef CIRCLE_PAINTER_H
#define CIRCLE_PAINTER_H

#include <GL\glut.h>
#include "Circle.h"
#include "Painter.h"



class CirclePainter : public Painter{
private:
	Circle* pCircle;
public:
	CirclePainter(Circle* pCircle);
	void draw() override;
	CirclePainter* newInstance(Shape* shape) override;
};

#endif // !1