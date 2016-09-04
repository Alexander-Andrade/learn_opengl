#ifndef SHAPE_H
#define SHAPE_H
#include "Painter.h"
#include <memory>
using namespace std;


class Shape
{
private:
	std::unique_ptr<Painter> painter;
public:
	Shape() {}
	virtual ~Shape() {}

	void draw() {
		painter->draw();
	}

	void setPainter(Painter * pPainter) {
		this->painter.reset(pPainter);
	}
};

#endif