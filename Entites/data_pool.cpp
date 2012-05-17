#include "data_pool.h"

DataPool::DataPool()
{

}
void DataPool::Initialize()
{

	b2Vec2 gravity(0.0f, 10.0f);
	world=new b2World(gravity,true);

	timeStep =24.0f;
	velocityIterations = 10;
	positionIterations = 6;


	aabb.lowerBound.Set(-1.0f, -400.0f);
	aabb.upperBound.Set(1.0f, 1.0f);

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(880.0f, 40.0f);

	bodyDef.allowSleep=false;

	worldAxis.Set(1.0f, 0.0f);

	bodyDef.type=b2_dynamicBody;
	bodyDef.position.Set(180.0f,40.0f);

	tempbody=world->CreateBody(&bodyDef);

	b2CircleShape tempball;
	tempball.m_radius=20;

	tempbody->CreateFixture(&tempball,1);
	
}

void DataPool::drawCircle( CL_GraphicContext *gc,b2Body *bodyref )
{
	CL_Draw::circle(*gc,
		bodyref->GetPosition().x,
		bodyref->GetPosition().y,
		bodyref->GetFixtureList()->GetShape()->m_radius,
		CL_Colorf::blueviolet);
}

void DataPool::update()
{
	world->Step(1.0f/ timeStep,velocityIterations,positionIterations);
}