#include "app.h"
#include "../libs/querryback.h"
#include "../Libs/Converter.h"
#include <time.h>



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
		_datapool.update();
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
	//ÅäÖÃÊÂ¼þ²å²Û
	slotMouseMove = mMouse.sig_pointer_move().connect(this,
		&T_App::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,
		&T_App::onMouseDown);
	slotMouseUp=mMouse.sig_key_up().connect(this,
		&T_App::onMouseUp);
	slotKeyboardUp=mKeyboard.sig_key_up().connect(this, 
		&T_App::onKeyboardUp);
	slotKeyPressed=mKeyboard.sig_key_down().connect(this,&T_App::onKeyboardDown);

	return 0;
}

void T_App::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
// 	if (key.id==CL_KEY_A)
// 	{
// 		_datapool.tempbox->SetAngularVelocity(1.0f);
// 		CL_Console::write_line("%1",_datapool.tempbox->GetAngle());
// 	}
}

void T_App::onKeyboardDown(const CL_InputEvent &key,
						 const CL_InputState &state)
{
	//CL_Console::write_line("%1",_datapool.tempbox->GetAngle());
	if (key.id==CL_KEY_A)
	{
		_datapool.tempbox->SetAngularVelocity(-0.1f);
		/*CL_Console::write_line("%1",_datapool.tempbox->GetAngle());*/
	}

	if (key.id==CL_KEY_D)
	{
		_datapool.tempbox->SetAngularVelocity(0.1f);
		/*CL_Console::write_line("%1",_datapool.tempbox->GetAngle());*/
	}

	if(key.id==CL_KEY_ESCAPE)
	{
		mQuit=1;
	}
}