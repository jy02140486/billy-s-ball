#include "DestructionListener.h"
#include <ClanLib/core.h>
#include "../Libs/RandomVal.h"

void DestructionListener::BeginContact(b2Contact* contact)
{
	b2Body*bodyA=contact->GetFixtureA()->GetBody();
	b2Body*bodyB=contact->GetFixtureB()->GetBody();

	if (bodyA->GetType()!=b2_dynamicBody||bodyB->GetType()!=b2_dynamicBody)
	{
		return;
	}
}