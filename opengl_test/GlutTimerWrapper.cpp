#include "GlutTimerWrapper.h"

void GlutTimerWrapper::timerFunc(int value){
	GlutTimerWrapper* pTimer = (GlutTimerWrapper*)value; //only x86
	pTimer->onTimer();
	if (pTimer->isRepeat && pTimer->isStarted)
		glutTimerFunc(pTimer->msecs, timerFunc, (int)pTimer);
	else
		pTimer->isStarted = false;
}

GlutTimerWrapper::GlutTimerWrapper(bool isRepeat, int msecs){
	this->isStarted = false;
	this->isRepeat = isRepeat;
	this->msecs = msecs;
}

void GlutTimerWrapper::start(){
	if (!isStarted) {
		glutTimerFunc(msecs, timerFunc, (int)this);
		isStarted = true;
	}
}

void GlutTimerWrapper::stop(){
	isStarted = false;
}
