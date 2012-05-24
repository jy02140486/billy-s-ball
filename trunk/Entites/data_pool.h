#ifndef DATA_POOL_H
#define DATA_POOL_H

#include "../Engine/precomp.h"

class DataPool
{

public:
	CL_GraphicContext *gc_ref;

	b2Body *tempbody;
	b2World *world;
	b2BodyDef bodyDef;
	b2Vec2 worldAxis;
	b2AABB aabb;

	//Billy's
	b2Body *Billy;
	CL_Image *BillyImg;
	

	float32 timeStep ;
	int32 velocityIterations ;
	int32 positionIterations ;

	b2Body *tempbox;

	void Initialize();
	void drawCircle(CL_GraphicContext *gc,b2Body *bodyref);

	DataPool();
	void update();
	void drawbox(CL_GraphicContext *gc,b2Body *bodyref);
	void drawBilly(CL_GraphicContext *gc,b2Body *bodyref);
};
#endif