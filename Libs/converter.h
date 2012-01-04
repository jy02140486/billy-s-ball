#ifndef CONVETER_H
#define CONVETER_H

#include "../engine/app.h"

class Converter
{
public:
	static CL_Vec2i Vec2from_b_to_c(b2Vec2 ref);
	static	b2Vec2 Vec2from_c_to_b(CL_Vec2i ref);
protected:
private:
};
#endif