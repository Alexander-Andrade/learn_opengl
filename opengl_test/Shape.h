#ifndef SHAPE_H
#define SHAPE_H
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
	Shape() {}
	virtual ~Shape() {}

	void draw();
	


	void setPainter(Painter * pPainter);
};

#endif