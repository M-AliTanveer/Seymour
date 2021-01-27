#pragma once
#include "flavours.h"
class seekh_kebab :
	public flavour
{
private:
    bool lamb;
    bool beef;
    static bool gluten;
    static int count;
public:
    seekh_kebab();
    bool get_lamb();
    void set_lamb(bool B);
    bool get_beef()const;
    void set_beef(bool B);
    static bool get_gluten();
    char* get_Addon();
    double set_meat(char choice[30]);
};

