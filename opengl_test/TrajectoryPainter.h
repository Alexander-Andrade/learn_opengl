#ifndef TRAJECTORY_PAINTER_H
#define TRAJECTORY_PAINTER_H

#include <GL\glut.h>
#include "Painter.h"
#include "Trajectory.h"

struct Trajectory;

class TrajectoryPainter : public Painter{
private:
	Trajectory* pTrajectory;
public:
	TrajectoryPainter(Trajectory* pTrajectory);

	void draw() override;
	TrajectoryPainter* newInstance(Shape* shape) override;
};



#endif
