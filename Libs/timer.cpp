#include "timer.h"


void Timer::init(int seconds,bool repeatflag)
{
	length=seconds;
    cursecond=0;
}

int Timer::get_curSec()
{
	int cur=(CL_System::get_time()-startflag)/1000;
	int res = cur>length?-1:cur;
	if (res==-1)
	{
		//CL_Timer::stop();
		return -1;
	}
	else return cur;
}

void Timer::begin()
{
	startflag=CL_System::get_time();
	//CL_Console::write_line("%1",length);
	start(length*1000,false);
}

Timer::Timer()
{
	timingobj=NULL;
}

void Timer::begin(bool isRepeating)
{
	startflag=CL_System::get_time();
	//CL_Console::write_line("%1",length);
	start(length*1000,isRepeating);
}