#include "Shape.h"

void Shape::draw(){
	painter->draw();
}

void Shape::copyPainter(Painter* painter){
	this->painter.reset(painter->newInstance(this));
}

void Shape::setPainter(Painter * pPainter){
	this->painter.reset(pPainter);
}
