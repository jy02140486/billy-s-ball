#ifndef DATA_POOL_H
#define DATA_POOL_H

#include "../Engine/precomp.h"
#include "ContactListener.h"
#include "../Libs/timer.h"

class DataPool
{

public:
	
	//b2worlds'
	float32 timeStep ;
	int32 velocityIterations ;
	int32 positionIterations ;
	b2World *world;
	b2Vec2 worldAxis;
	b2AABB aabb;

	//CLs'
	CL_GraphicContext *gc_ref;

	//Logics'
	b2Body *		tempbox;
	b2Body *		tempbody;
	b2BodyDef		bodyDef;

	b2Body			*curbody;

	//Billy's
	b2Body	*		Billy;
	CL_Image *		BillyImg;
	CL_Image*		AllClear;

	//kinematic platform
	b2BodyDef		kPlatformDef;
	b2Body*			kPlatform;
	b2PolygonShape	kPlatformShape;

	//Bullet
	b2CircleShape	bulletshape;
	b2BodyDef		bulletbodydef;
	b2FixtureDef	bulletfixturedef;
	Timer *			bullettimer;
	
	//Catapult
	b2PolygonShape	catapultshape;
	b2BodyDef		catapultbodydef;
	b2Body	*		catapult;

	void Initialize();
	void drawCircle(CL_GraphicContext *gc,b2Body *bodyref);

	DataPool();
	void update();
	void drawbox(CL_GraphicContext *gc,b2Body *bodyref);
	void drawBilly(CL_GraphicContext *gc,b2Body *bodyref);
	void Reset();
	void setConvexVertex(b2PolygonShape *shapeDef,int n,float32 radius);
	void OnBulletTimeUp();
	void drawall();
};
#endif