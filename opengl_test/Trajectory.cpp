#include "Trajectory.h"


Trajectory::Trajectory(Shape * shape, GLfloat timerDuration, Point initPosition, bool isMoving=false) : Shape(new TrajectoryPainter(this)),
GlutTimerWrapper(isMoving, timerDuration){
	this->shape = shape;
	this->timerDuration = timerDuration;
	this->curPosition = initPosition;
}

void Trajectory::moveShape(){
	shape->setGravityCenterCoords(curPosition.x, curPosition.y, curPosition.z);
}

void Trajectory::onTimer(){
	moveShape();
	glutPostRedisplay();
}

