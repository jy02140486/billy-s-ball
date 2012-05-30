#include "app.h"
#include <stdio.h>
#include "../Libs/Converter.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);
	
	switch (global_state)
	{
	case COMMON:
		_datapool.drawCircle(&(mpDisplayWindow->get_gc()),_datapool.tempbody);
		_datapool.drawbox(&(mpDisplayWindow->get_gc()),_datapool.tempbox);
		_datapool.drawbox(&(mpDisplayWindow->get_gc()),_datapool.Billy);
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
