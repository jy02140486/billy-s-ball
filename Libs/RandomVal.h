#ifndef RANDOMVAL_H
#define RANDOMVAL_H

#include <stdlib.h>
#include <ClanLib/core.h>
#include <box2d/Box2D.h>

class RandomVal
{
public:
	static	int int_from_to(int from,int to);
	static CL_Point* randomPointi(int x1,int y1,int x2,int y2);
	static bool randombool();
	static b2Vec2 randomvec(int maxv);
protected:
private:
	
};
#endif