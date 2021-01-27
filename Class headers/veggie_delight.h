#pragma once
#include "flavours.h"
class veggie_delight :
	public flavour
{
private:
    static bool gluten;
    static int count;
public:
    veggie_delight();
    static bool get_gluten();
    char* get_Addon();
};

