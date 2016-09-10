#include "GlutTimerWrapper.h"

void GlutTimerWrapper::timerFunc(int value){
	GlutTimerWrapper* pTimer = (GlutTimerWrapper*)value; //only x86
	pTimer->onTimer();
	if (pTimer->isRepeat && pTimer->isStarted)
		glutTimerFunc(pTimer->msDuration, timerFunc, (int)pTimer);
	else
		pTimer->isStarted = false;
}

GlutTimerWrapper::GlutTimerWrapper(bool isRepeat, int msDuration){
	this->isStarted = false;
	this->isRepeat = isRepeat;
	this->msDuration = msDuration;
}

void GlutTimerWrapper::setDuration(int msDuration){
	this->msDuration = msDuration;
}

void GlutTimerWrapper::start(){
	if (!isStarted) {
		glutTimerFunc(msDuration, timerFunc, (int)this);
		isStarted = true;
	}
}

void GlutTimerWrapper::stop(){
	isStarted = false;
}
