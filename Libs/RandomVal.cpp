#include "RandomVal.h"

int RandomVal::int_from_to(int from,int to)
{
	return from+rand()%(to-from+1);
}

CL_Point* RandomVal::randomPointi( int x1,int y1,int x2,int y2 )
{
	int x=x1+rand()%(x2+1-x1);
	int y=y1+rand()%(y2+1-y1);
	return new CL_Point(x,y);
}

bool RandomVal::randombool()
{
	int a=rand()%100+1;
	if (a>50)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

b2Vec2 RandomVal::randomvec(int maxv)
{
	int x=rand()%maxv+1;
	int y=rand()%maxv+1;

	if (randombool())
	{
		x*=-1;
	}
	if (randombool())
	{
		y*=-1;
	}

	return b2Vec2(x,y);
}