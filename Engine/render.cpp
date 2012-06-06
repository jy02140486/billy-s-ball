#include "app.h"
#include <stdio.h>
#include "../Libs/Converter.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);
	
	words->draw_text(mpDisplayWindow->get_gc(),0,20,"Press A/D to act, Space to reset, Esc to Quit",CL_Colorf::yellow);
	words->draw_text(mpDisplayWindow->get_gc(),0,_datapool.screenH-40,"Deliever the ball back to Billy",CL_Colorf::yellow);

	switch (global_state)
	{
	case COMMON:

		_datapool.drawall();
		_datapool.drawBilly(&(mpDisplayWindow->get_gc()),_datapool.Billy);
		break;
	case ALL_CLEAR:
		_datapool.AllClear->draw(mpDisplayWindow->get_gc(),10,400);
		break;
	default:;
	}

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
	
}
