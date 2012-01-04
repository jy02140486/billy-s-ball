#ifndef TIMER_H
#define TIMER_H

#include <ClanLib/core.h>
class Timer:public CL_Timer
{
public:
	int length;
	int cursecond;
	int secondsleft;

	void* timingobj;

	int startflag;
	void init(int seconds,bool repeatflag);
	int get_curSec();
	void begin();
	void begin(bool isRepeating);
	Timer();
	

protected:
private:
};
#endif