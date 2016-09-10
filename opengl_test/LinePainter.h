#ifndef LINE_PAINTER_H
#define LINE_PAINTER_H

#include <GL\glut.h>
#include "Painter.h"
#include "Line.h"

using namespace std;

struct Line;

class LinePainter : public Painter {
private:
	Line* pLine;
public:
	LinePainter(Line* pLine);
	void draw() override;
	LinePainter* newInstance(Shape* shape) override;
};

#endif
