#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <box2d/Box2D.h>
class ContactListener :public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

#endif