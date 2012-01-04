#ifndef EVENT_H
#define EVENT_H 
#include "precomp.h"



class T_Event
{	 	
public:
	T_Event();

protected:
	
	CL_DisplayWindowDescription		mWinDesc;
	CL_DisplayWindow *				mpDisplayWindow;
	CL_GUIManager					mGui;
	CL_GUIWindowManagerTexture *	mpWinManager;
	


	//resource
	CL_ResourceManager mResManager;
	CL_GUIThemeDefault mGUITheme;

	//Main GUIComponet window
	CL_Window *mpComWindow;

	//console window
	CL_ConsoleWindow *mpConsole;

	//input context
	CL_InputContext mInput;

	//keyboard context
	CL_InputDevice mKeyboard;

	//mouse context
	CL_InputDevice mMouse;

	//joystick context
	//CL_InputDevice mJoystick;

	bool mQuit;

	//以下为slots：
	CL_Slot		slotWindowClose;
//	CL_Slot slotWindowClose;
	CL_Slot		slotKeyboardUp;
	CL_Slot		slotMouseMove;
	CL_Slot		slotMouseDown;
	CL_Slot	slotMouseUp;

	int		eventInit();

	//以下为事件处理具体函数：
	//-其他事件
	void	onExitApp();

	//-键盘事件
	void onKeyboardUp(const CL_InputEvent &, const CL_InputState &);


	//-鼠标事件
	void onMouseMove(const CL_InputEvent &, const CL_InputState &);
	void onMouseDown(const CL_InputEvent &, const CL_InputState &);
	void onMouseUp(const CL_InputEvent &, const CL_InputState &);
	
public:

};
#endif
