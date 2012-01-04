#include <ClanLib/application.h>

#include "main.h"
#include "app.h"

CL_ClanApplication app(&T_Main::main);

/** 
 * @brief Program initial
 * 
 * @param args
 * 
 * @return 
 */
int T_Main::main(const std::vector<CL_String> &args)
{
	//Initial ClanLib base component
	CL_SetupCore setup_core;

	//Initial ClanLib display component
	CL_SetupDisplay setup_display;

	//Initial GUI
	CL_SetupGUI	setup_gui;

	//Initial OpenGl driver
	CL_SetupGL setup_gl;

	//Start the application
	T_App app;
	int retval = app.start();

	return retval;
}

