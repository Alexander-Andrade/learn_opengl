#include "CirclePainter.h"

CirclePainter::CirclePainter(Circle * pCircle){
	this->pCircle = pCircle;
}

void CirclePainter::draw(){
}

CirclePainter * CirclePainter::newInstance(Shape * shape){
	return new CirclePainter((Circle*)shape);
}
