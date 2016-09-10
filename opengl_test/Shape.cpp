#include "Shape.h"

void Shape::draw(){
	painter->draw();
}

void Shape::copyPainter(Painter* painter){
	Painter* newPainter = painter->newInstance(this);
	this->painter.reset(newPainter);
}

Shape::Shape(Painter* painter){
	this->painter.reset(painter);
}

void Shape::setPainter(Painter * pPainter){
	this->painter.reset(pPainter);
}
