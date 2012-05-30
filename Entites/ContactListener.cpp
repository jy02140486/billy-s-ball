#include "ContactListener.h"
#include <ClanLib/core.h>


void ContactListener::BeginContact(b2Contact* contact)
{
	CL_Console::write_line("contact!");
	
	b2Body *tb=contact->GetFixtureA()->GetBody();

	if (tb->GetUserData()==NULL)
	{
		return;
	}
	int *i=(int*)tb->GetUserData();
	if (*i==1)
	{
		CL_Console::write_line("win");
	}

	tb=contact->GetFixtureB()->GetBody();
	if (tb->GetUserData()==NULL)
	{
		return;
	}
	i=(int*)tb->GetUserData();
	if (*i==1)
	{
		CL_Console::write_line("win");
	}
	
}

void ContactListener::EndContact(b2Contact* contact)
{
	CL_Console::write_line("Disengage!");
}