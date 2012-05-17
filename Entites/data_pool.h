#ifndef DATA_POOL_H
#define DATA_POOL_H

#include "../Engine/precomp.h"

class DataPool
{

public:
	b2Body *tempbody;
	b2World *world;
	b2BodyDef bodyDef;
	b2Vec2 worldAxis;
	b2AABB aabb;

	float32 timeStep ;
	int32 velocityIterations ;
	int32 positionIterations ;

	b2Body *tempbox;

	void Initialize();
	void drawCircle(CL_GraphicContext *gc,b2Body *bodyref);

	DataPool();
	void update();
};
#endif