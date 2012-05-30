#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <box2d/Box2D.h>
#include "../Engine/globals.h"
#include <ClanLib/core.h>

class ContactListener :public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void setVic(b2Contact* contact);
	void Finish();

};

#endif