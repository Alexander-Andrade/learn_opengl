#include "TrajectoryPainter.h"


TrajectoryPainter::TrajectoryPainter(Trajectory* pTrajectory){
	this->pTrajectory = pTrajectory;
}

void TrajectoryPainter::draw(){
}

TrajectoryPainter * TrajectoryPainter::newInstance(Shape * shape){
	return new TrajectoryPainter((Trajectory*)shape);
}

