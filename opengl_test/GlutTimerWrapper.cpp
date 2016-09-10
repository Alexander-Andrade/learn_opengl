#include "GlutTimerWrapper.h"

void GlutTimerWrapper::timerFunc(int value){
	GlutTimerWrapper* pTimer = (GlutTimerWrapper*)value; //only x86
	pTimer->onTimer();
	if (pTimer->isRepeat)
		glutTimerFunc(pTimer->msecs, timerFunc, (int)pTimer);
}

GlutTimerWrapper::GlutTimerWrapper(bool isRepeat, int msecs){
	this->isRepeat = isRepeat;
	this->msecs = msecs;
}

void GlutTimerWrapper::start(){
	if (isRepeat == true) return;
	isRepeat = true;
	glutTimerFunc(msecs, timerFunc, (int)this);
}

void GlutTimerWrapper::stop(){
	isRepeat = false;
}
