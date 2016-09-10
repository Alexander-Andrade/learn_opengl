#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <GL/glut.h>
#include "Shape.h"
#include "Point.h"
#include "GlutTimerWrapper.h"
#include "TrajectoryPainter.h"

//decorator
struct Trajectory : public Shape, public GlutTimerWrapper{
private:
	Shape* shape;
	Point curPosition;
public:
	GLfloat timerDuration;
	Trajectory(Shape* shape, GLfloat timerDuration, Point initPosition, bool isMoving);
	virtual void moveShape();
	void onTimer() override;
};



#endif
