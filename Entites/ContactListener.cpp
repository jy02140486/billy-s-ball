#include "ContactListener.h"


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
		setVic(contact);
	}

	tb=contact->GetFixtureB()->GetBody();
	if (tb->GetUserData()==NULL)
	{
		return;
	}
	i=(int*)tb->GetUserData();
	if (*i==1)
	{
		setVic(contact);
	}
	
}

void ContactListener::EndContact(b2Contact* contact)
{
	CL_Console::write_line("Disengage!");
}

void ContactListener::setVic(b2Contact* contact)
{
	global_state=ALL_CLEAR;
}
