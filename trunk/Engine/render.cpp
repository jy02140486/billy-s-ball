#include "app.h"
#include <stdio.h>
#include "../Libs/Converter.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);
	
	
	

	switch (global_state)
	{
	case COMMON:
		_datapool.drawall();
		_datapool.drawBilly(&(mpDisplayWindow->get_gc()),_datapool.Billy);
		words->draw_text(mpDisplayWindow->get_gc(),40,_datapool.screenH-30,"Deliever the ball back to Billy",CL_Colorf::yellow);
		words->draw_text(mpDisplayWindow->get_gc(),40,20,"Press A/D to act, Space to reset, Esc to Quit",CL_Colorf::yellow);
		break;
	case ALL_CLEAR:
		words->draw_text(mpDisplayWindow->get_gc(),40,_datapool.screenH-30,"Good job!",CL_Colorf::yellow);
		words->draw_text(mpDisplayWindow->get_gc(),40,20,"Press Space to restart, Esc to Quit",CL_Colorf::yellow);
		_datapool.AllClear->draw(mpDisplayWindow->get_gc(),10,_datapool.screenH/3);
		break;
	default:;
	}

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
	
}
