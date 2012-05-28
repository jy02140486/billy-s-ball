#include "ContactListener.h"
#include <ClanLib/core.h>


void ContactListener::BeginContact(b2Contact* contact)
{
	CL_Console::write_line("contact!");
	
}

void ContactListener::EndContact(b2Contact* contact)
{
	CL_Console::write_line("Disengage!");
}