#pragma once
#include "flavours.h"
class chilli_delight :
	public flavour
{
private:
    bool chicken;
    bool red;bool green;
    static bool gluten;
    static int count;
public:
    chilli_delight();
     double set_chilli(char *choice);
    static bool get_gluten();
    char* get_Addon();
};


