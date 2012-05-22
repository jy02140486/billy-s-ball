#include "data_pool.h"

DataPool::DataPool()
{

}
void DataPool::Initialize()
{

	b2Vec2 gravity(0.0f, 10.0f);
	world=new b2World(gravity,true);

	timeStep =6.0f;
	velocityIterations = 20;
	positionIterations = 15;


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

	tempbody->CreateFixture(&tempball,10);

	b2PolygonShape tempboxdef;
	tempboxdef.SetAsBox(320,16);

	bodyDef.position.Set(220,180);
	bodyDef.type=b2_kinematicBody;
	tempbox=world->CreateBody(&bodyDef);
	tempbox->CreateFixture(&tempboxdef,1);
	
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

void DataPool::drawbox(CL_GraphicContext *gc,b2Body *bodyref)
{
	b2PolygonShape* shape=(b2PolygonShape*)bodyref->GetFixtureList()->GetShape();


	CL_Vec4f red_color(1.0f, 0.0f, 0.0f, 1.0f);
	CL_Vec4f green_color(0.0f, 1.0f, 0.0f, 1.0f);
	CL_Vec4f colour_grey(128.0f, 128.0f,128.0f, 128.0f);



	const int vn=shape->GetVertexCount();
	CL_Vec2i positions[8];
	CL_Vec4f colors[] = { red_color, green_color,red_color, green_color,red_color, green_color,red_color, green_color};
	CL_Vec4f ground[]={colour_grey,colour_grey,colour_grey,colour_grey,colour_grey,colour_grey,colour_grey,colour_grey};


	float32 angle=b2_pi/shape->m_vertexCount;

	b2Transform tmptf=bodyref->GetTransform();
	b2Vec2 tmpvec;

	for (int i=0;i<vn;i++)
	{
		tmpvec=b2Mul(tmptf,shape->GetVertex(i));
		positions[i]=CL_Vec2f(tmpvec.x,tmpvec.y);	
	}


	CL_PrimitivesArray vecs(*gc);

	vecs.set_attributes(0,positions);


//	if (bodyref->GetType()==b2_dynamicBody)
		vecs.set_attributes(1,colors);
// 	else
// 		vecs.set_attributes(1,ground);

	gc->set_program_object(cl_program_color_only);
	gc->draw_primitives(cl_line_loop,vn,vecs);
}