#include "Converter.h"

CL_Vec2i Converter::Vec2from_b_to_c(b2Vec2 ref)
{
	return CL_Vec2i(ref.x,ref.y);
}

b2Vec2 Converter::Vec2from_c_to_b(CL_Vec2i ref)
{
	return b2Vec2(ref.x,ref.y);
}