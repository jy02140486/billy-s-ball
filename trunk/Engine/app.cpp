#include "app.h"
#include "../libs/querryback.h"
#include "../Libs/Converter.h"
#include <time.h>

#define FPS 44

T_App::T_App()
{
	/* code */
}

int T_App::start()
{
	srand (time(NULL));

	if (init() == false)
	{
		return -1;
	}

	global_state=STRATGY;

	int fps=FPS;
	mrk=GetTickCount();

	while (!mQuit)
	{
		if (GetTickCount()-mrk>1000/fps)
		{
			mGui.exec(false);
			loop();
			mrk=GetTickCount();
		}
		else Sleep(1000.0/fps-(GetTickCount()-mrk));
	}

	return 0;
}

void T_App::onMouseUp(const CL_InputEvent &, const CL_InputState &)
{
	
}



void T_App::onMouseDown(const CL_InputEvent &, const CL_InputState &)
{
	
}

void T_App::onMouseMove(const CL_InputEvent &, const CL_InputState &)
{

}


int T_App::eventInit()
{
	//≈‰÷√ ¬º˛≤Â≤€
	slotMouseMove = mMouse.sig_pointer_move().connect(this,
		&T_App::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,
		&T_App::onMouseDown);
	slotMouseUp=mMouse.sig_key_up().connect(this,
		&T_App::onMouseUp);
	slotKeyboardUp=mKeyboard.sig_key_up().connect(this, 
		&T_App::onKeyboardUp);

	return 0;
}

void T_App::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
	
}

