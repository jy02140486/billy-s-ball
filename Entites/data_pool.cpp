#include "data_pool.h"
#include "../Engine/globals.h"

#define M_PI       3.14159265358979323846

DataPool::DataPool()
{

}
void DataPool::Initialize()
{

	b2Vec2 gravity(0.0f, 10.0f);
	world=new b2World(gravity,true);

	timeStep =44;
	velocityIterations = 4;
	positionIterations = 2 ;


	aabb.lowerBound.Set(-1.0f, -400.0f);
	aabb.upperBound.Set(1.0f, 1.0f);

	bodyDef.allowSleep=false;

	worldAxis.Set(1.0f, 0.0f);

	bodyDef.type=b2_dynamicBody;
	bodyDef.position.Set(180.0f,40.0f);

	tempbody=world->CreateBody(&bodyDef);

	b2CircleShape tempball;
	tempball.m_radius=20;

	tempbody->CreateFixture(&tempball,10);
	tempbody->SetUserData(this);

	b2PolygonShape tempboxdef;
	tempboxdef.SetAsBox(100,10);

	bodyDef.position.Set(220,180);
	bodyDef.type=b2_kinematicBody;
	tempbox=world->CreateBody(&bodyDef);
	tempbox->CreateFixture(&tempboxdef,1);
	
	bodyDef.position.Set(100,740);
	bodyDef.type=b2_kinematicBody;

	Billy=world->CreateBody(&bodyDef);
	BillyImg=new CL_Image(*gc_ref,"res/withoutBall.png");
	tempboxdef.SetAsBox(BillyImg->get_width()/2,BillyImg->get_height()/2);

	Billy->CreateFixture(&tempboxdef,1);

	b2Vec2 rightward(40,0);
	Billy->SetLinearVelocity(rightward);
	int *i=new int(1);
	Billy->SetUserData(i);

	world->SetContactListener(new ContactListener());

	AllClear=new CL_Image(*gc_ref,"res/back.png");


	//kinematic plaform
	kPlatformDef.position.Set(50,400);
	kPlatformDef.type=b2_kinematicBody;
	kPlatform=world->CreateBody(&kPlatformDef);
	kPlatformShape.SetAsBox(40,5);
	kPlatform->CreateFixture(&kPlatformShape,50);

	//bullet
	bulletshape.m_radius=0.25f;
	bulletfixturedef.shape=&bulletshape;
	bulletfixturedef.density=10;
	bulletfixturedef.restitution=0.2f;
	bulletbodydef.type=b2_dynamicBody;
	bulletbodydef.bullet=true;

	//catapult
	catapultbodydef.position.Set(540,540);
	catapultbodydef.type=b2_kinematicBody;
	catapult=world->CreateBody(&catapultbodydef);
	setConvexVertex(&catapultshape,3,20);
	catapult->CreateFixture(&catapultshape,50);
	catapult->SetAngularVelocity(0.5f);
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
	switch(global_state)
	{
	case COMMON:
		world->Step(1.0f/ timeStep,velocityIterations,positionIterations);

		if (Billy->GetPosition().x+BillyImg->get_width()/2>640
			||Billy->GetPosition().x-BillyImg->get_width()/2<0)
		{
			Billy->SetLinearVelocity(-Billy->GetLinearVelocity());
		}

		if (kPlatform->GetPosition().x<0||kPlatform->GetPosition().x>600)
		{
			b2Vec2 tempVec(0,0);
			kPlatform->SetLinearVelocity(tempVec);
		}
		break;
	case ALL_CLEAR:
		break;
	}
	
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


void DataPool::drawBilly(CL_GraphicContext *gc,b2Body *bodyref)
{
	BillyImg->draw(*gc,bodyref->GetPosition().x-BillyImg->get_width()/2,bodyref->GetPosition().y-BillyImg->get_height()/2);
}

void DataPool::Reset()
{
	global_state=COMMON;
	
	if (tempbody!=NULL)
	{
		world->DestroyBody(tempbody);
	}

	if (tempbox!=NULL)
	{
		world->DestroyBody(tempbox);
	}

	//reset the ball
	bodyDef.type=b2_dynamicBody;
	bodyDef.position.Set(180.0f,40.0f);
	tempbody=world->CreateBody(&bodyDef);

	//reset the turning box
	b2PolygonShape tempboxdef;
	tempboxdef.SetAsBox(100,10);

	bodyDef.position.Set(220,180);
	bodyDef.type=b2_kinematicBody;
	tempbox=world->CreateBody(&bodyDef);
	tempbox->CreateFixture(&tempboxdef,1);

	b2CircleShape tempball;
	tempball.m_radius=20;

	tempbody->CreateFixture(&tempball,10);
	tempbody->SetUserData(this);

	//reset the kPlatform
	if (kPlatform!=NULL)
	{
		world->DestroyBody(kPlatform);
	}
	kPlatformDef.position.Set(50,400);
	kPlatformDef.type=b2_kinematicBody;
	kPlatform=world->CreateBody(&kPlatformDef);
	kPlatformShape.SetAsBox(40,5);
	kPlatform->CreateFixture(&kPlatformShape,50);
}



//set vertexes Attributes
void DataPool::setConvexVertex(b2PolygonShape *shapeDef,int n,float32 radius) 

{  
	shapeDef->m_vertexCount = n;  

	float32 Pi=M_PI;

	float32 angle=Pi * 2 / n;  

	float32 dx,dy;

	for (int i= 0; i < n;i++ )  
	{  
		dx = radius * cos(angle * i-angle/2);  
		dy = radius *sin(angle * i-angle/2);  
		shapeDef->m_vertices[i].Set(dx,dy);  

		CL_Console::write_line("v%1 x=%2 y=%3",i,dx,dy);
	}  


	shapeDef->Set(shapeDef->m_vertices,n);
	//  shapeDef->m_radius=radius;
}  