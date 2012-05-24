#include "app.h"
#include <stdio.h>
#include "../Libs/Converter.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::black);
	

	_datapool.drawCircle(&(mpDisplayWindow->get_gc()),_datapool.tempbody);
	_datapool.drawbox(&(mpDisplayWindow->get_gc()),_datapool.tempbox);
	_datapool.drawbox(&(mpDisplayWindow->get_gc()),_datapool.Billy);

	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
		
	mpDisplayWindow->flip();
	
}
