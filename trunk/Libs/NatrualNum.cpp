#include "NatrualNum.h"

void NatrualNum::plus(int addnum)
{ 
	val+=addnum;
	if (val>maximun)
	{
		val=maximun;
	}
}

void NatrualNum::minus(int minnum)
{
	val-=minnum;
	if (val<0)
	{
		val=0;
	}
}

bool NatrualNum::minusable(int minnum)
{
	int temp=val-minnum;
	
	if (temp<0)
		return false;
	
	return true;

}

bool NatrualNum::plusable(int addnum)
{ 
	int temp=val+addnum;

	if (temp>maximun)
		return false;

	return true;

}

NatrualNum::NatrualNum(int valref,int max)
{
	this->val=valref;
	maximun=max;
}

NatrualNum::NatrualNum(int max)
{
	val=max;
	maximun=max;
}

