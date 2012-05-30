#ifndef APP_H
#define APP_H 

#include "precomp.h"
#include "event.h"

#include "globals.h"
#include "../Entites/data_pool.h"

#include <list>
#include<stdio.h>


class T_App : public T_Event	
{


public:
	T_App ();
	int  start();
	bool running;

	//entites
	DataPool _datapool;
	
	CL_Font *words;
	CL_Point offset;

	
	CL_Signal_v1<GLOBAL_STATE> sig_state;
	CL_Slot slot_stateChanged;


	CL_Signal_v1<int> sig_test;
	CL_Slot slot_intChanged;

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
	void onKeyboardDown(const CL_InputEvent &key, const CL_InputState &state);
	void OnStateChange(GLOBAL_STATE state);
	void Finish();
	void EndAll();
	void OnIntChanged(int v);
};

#endif
