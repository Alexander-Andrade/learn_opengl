#ifndef GLUT_TIMER_WRAPPER_H
#define GLUT_TIMER_WRAPPER_H
#include <GL/glut.h>

class GlutTimerWrapper
{
private:
	bool isStarted;
protected:
	bool isRepeat;
	int msecs;
	static void timerFunc(int value);
public:
	GlutTimerWrapper(bool isRepeat,int msecs);
	virtual void onTimer() = 0;
	void start();
	void stop();
};

#endif // !1