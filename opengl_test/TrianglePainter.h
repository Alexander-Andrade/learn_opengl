#ifndef TRIANGLE_PAINTER_H
#define TRIANGLE_PAINTER_H

#include <GL\glut.h>
#include "Painter.h"
#include "Triangle.h"

struct Triangle;

class TrianglePainter : public Painter{
private:
	Triangle* pTriangle;
public:
	TrianglePainter(Triangle* pTriangle);
	void draw() override;
	TrianglePainter* newInstance(Shape* shape) override;
};

#endif // !TRIANGLE_PAINTER_H
