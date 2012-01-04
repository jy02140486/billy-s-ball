#ifndef APP_H
#define APP_H 

#include "precomp.h"
#include "event.h"

#include "globals.h"

#include <list>
#include<stdio.h>


class T_App : public T_Event	
{


public:
	T_App ();
	int  start();
	bool running;

	
	CL_Font *words;
	CL_Point offset;

	time_t Atime;
	DWORD mrk;

	//initial game enviroment
	bool init();

	//processing game logics
	void loop();

	//render the game
	void render();
	

	//initial all
	int eventInit(void);

	void onMouseMove(const CL_InputEvent &, const CL_InputState &);
	void onMouseDown(const CL_InputEvent &, const CL_InputState &);
	void onMouseUp(const CL_InputEvent &, const CL_InputState &);
	void onKeyboardUp(const CL_InputEvent &key,
		const CL_InputState &state);

	//temp funcs
	void LibDebugOnConsole();
};

#endif
