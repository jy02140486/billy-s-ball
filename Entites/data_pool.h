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
	int screenH;

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

	//sides
	b2Body *		sideL,*sideR;
	b2BodyDef		sidesdef;
	

	//renders
	CL_Vec4f 		red_color;
	CL_Vec4f 		green_color;
	CL_Vec4f 		colour_grey;
	CL_Vec2i		positions[8];
	CL_Vec4f		colors[8];
	CL_Vec4f		ground[8];


	void Initialize(CL_GraphicContext*gc,int screen_high);
	void drawCircle(CL_GraphicContext *gc,b2Body *bodyref);

	DataPool();
	void update();
	void drawbox(CL_GraphicContext *gc,b2Body *bodyref);
	void drawBilly(CL_GraphicContext *gc,b2Body *bodyref);
	void Reset();
	void setConvexVertex(b2PolygonShape *shapeDef,int n,float32 radius,b2Vec2 offsetxy);
	void OnBulletTimeUp();
	void drawall();
	void drawCenterPoint( CL_GraphicContext *gc,b2Body *bodyref );
	void setRenderers();
};
#endif