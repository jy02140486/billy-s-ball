#include "app.h"
#include "../libs/querryback.h"
#include "../Libs/Converter.h"
#include <time.h>
#include "../Libs/timer.h"



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

	global_state=COMMON;

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
		if (global_state==ALL_CLEAR)
		{
			sig_state.invoke(ALL_CLEAR);
		}
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
	b2Vec2 temp;
	if (key.id==CL_KEY_A)
	{
		_datapool.tempbox->SetAngularVelocity(0);
		temp.Set(0,0);
		_datapool.kPlatform->SetLinearVelocity(temp);
		_datapool.catapult->SetAngularVelocity(0);
		_datapool.catapult->SetLinearVelocity(temp);
	}

	if (key.id==CL_KEY_D)
	{
		_datapool.tempbox->SetAngularVelocity(0);
		temp.Set(0,0);
		_datapool.kPlatform->SetLinearVelocity(temp);
		_datapool.catapult->SetAngularVelocity(0);
		_datapool.catapult->SetLinearVelocity(temp);
	}
}

void T_App::onKeyboardDown(const CL_InputEvent &key,
						 const CL_InputState &state)
{
	b2Vec2 temp;
	if(key.id==CL_KEY_ESCAPE)
	{
		EndAll();
	}

	if(key.id==CL_KEY_SPACE)
	{
		_datapool.Reset();
	}

	switch(global_state)
	{
	case COMMON:
		if (key.id==CL_KEY_A)
		{
			_datapool.tempbox->SetAngularVelocity(-0.2f);
			temp.Set(-80,0);
			_datapool.kPlatform->SetLinearVelocity(temp);
			_datapool.catapult->SetAngularVelocity(-0.4f);
			temp.Set(-60,0);
			_datapool.catapult->SetLinearVelocity(temp);
		}

		if (key.id==CL_KEY_D)
		{
			_datapool.tempbox->SetAngularVelocity(0.2f);
			temp.Set(80,0);
			_datapool.kPlatform->SetLinearVelocity(temp);
			_datapool.catapult->SetAngularVelocity(0.4f);
			temp.Set(60,0);
			_datapool.catapult->SetLinearVelocity(temp);
		}
		break;
	}
}

void T_App::OnStateChange(GLOBAL_STATE state)
{
	switch(state)
	{
	case ALL_CLEAR:
		Finish();
		break;
	}
}

void T_App::Finish()
{
	Timer *timer=new Timer();
	timer->init(4,false);
	timer->func_expired().set(this,&T_App::EndAll);
}

void T_App::EndAll()
{
	mQuit=true;
}

