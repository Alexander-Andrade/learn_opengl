#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glut.h>
#include "Painter.h"
#include <memory>

using namespace std;

class Painter;

class Shape
{
protected:
	std::unique_ptr<Painter> painter;
	void copyPainter(Painter* shape);
public:
	Shape(Painter* painter);
	virtual ~Shape() {}

	void draw();
	virtual void setGravityCenterCoords(GLfloat x, GLfloat y, GLfloat z) {}


	void setPainter(Painter * pPainter);
};

#endif