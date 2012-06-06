#include "app.h"
#include "event.h"
#include <time.h>

bool T_App::init()
{
	try
	{
	mpConsole = new CL_ConsoleWindow("Console", 80, 100);
	//initail window description
	mWinDesc.set_title("Billy's Ball");
	mWinDesc.set_allow_resize(false);
	mWinDesc.show_maximize_button(false);
	
	CL_ScreenInfo screen_info;
	int primary_screen;
	std::vector<CL_Rect> rects = screen_info.get_screen_geometries(primary_screen);
	for (std::vector<CL_Rect>::size_type i=0; i<rects.size(); i++)
	{
		CL_Console::write_line("Screen geometry: l:%1 t:%2  r:%3 b:%4 %5", rects[i].left, rects[i].top, rects[i].right, rects[i].bottom, i == primary_screen ? cl_format("- Primary (%1)", i) : "" );
	}
	
	const int h=rects[0].bottom-80;
	mWinDesc.set_size(CL_Size (640,h), false);

	
	CL_String resource("Res/GUITheme/resources.xml");
	CL_String theme("Res/GUITheme/theme.css");

	//initail resource manager
	mResManager.load(resource);

	////initail gui theme
	mGUITheme.set_resources(mResManager);

	//initail gui
	mpDisplayWindow = new CL_DisplayWindow(mWinDesc);
	mpWinManager = new CL_GUIWindowManagerTexture(*mpDisplayWindow);
	mGui.set_window_manager(*mpWinManager);
	mGui.set_theme(mGUITheme);
	mGui.set_css_document(theme);

	mpWinManager->func_repaint().set(this, &T_App::render);

	//initail GUIComponet window
	CL_DisplayWindowDescription comWindowDesc;
	comWindowDesc.show_border(false);
	comWindowDesc.set_allow_resize(true);
	comWindowDesc.set_title("settings");
	comWindowDesc.set_size(CL_Size(300, 570),false);
	comWindowDesc.set_allow_resize(true);
	comWindowDesc.set_layered(true);

	mpComWindow = new CL_Window(&mGui, comWindowDesc);
	mpComWindow->set_draggable(false);
	mpComWindow->set_visible(false);

	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();


	

	
	_datapool.Initialize(&mpDisplayWindow->get_gc(),h);
	//LibDebugOnConsole();

	slot_stateChanged=sig_state.connect(this,&T_App::OnStateChange);
	words=new CL_Font(mpDisplayWindow->get_gc(),"Tahoma",30);


	time(&Atime);
	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception:Init error",
			exception.get_message_and_stack_trace());
// 		mpConsole->display_close_message();
		CL_Console::write_line(exception.get_message_and_stack_trace());

		return true;
	}

	running=true;

	T_Event::eventInit();
	T_App::eventInit();

// 	slotMouseDown = mMouse.sig_key_down().connect(this,
// 		&T_App::onMouseDown);
	return true;
}

