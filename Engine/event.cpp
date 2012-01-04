#include "event.h"


T_Event::T_Event()
{
	mQuit = false;
}

int T_Event::eventInit()
{
	//配置事件插槽
	slotWindowClose = mpDisplayWindow->sig_window_close().connect(this,&T_Event::onExitApp);
	slotKeyboardUp = mKeyboard.sig_key_up().connect(this,&T_Event::onKeyboardUp);
	slotMouseMove = mMouse.sig_pointer_move().connect(this,&T_Event::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,&T_Event::onMouseDown);
	slotMouseUp=mMouse.sig_key_up().connect(this,&T_Event::onMouseUp);
	


	return 0;
}





//以下为事件处理具体函数：
//-其他事件
void T_Event::onExitApp()
{
	mQuit = true;
}

//-键盘事件

void T_Event::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
	if(key.id == CL_KEY_ESCAPE)
		mQuit = true;
}



//-鼠标事件
void T_Event::onMouseMove(const CL_InputEvent &key, const CL_InputState &state)
{


}

void T_Event::onMouseDown(const CL_InputEvent &key, const CL_InputState &state)
{
	 	


}

void T_Event::onMouseUp(const CL_InputEvent &, const CL_InputState &)
{
}
