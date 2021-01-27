#pragma once
#include <iostream>
#include "crust.h"
using namespace std;

enum oilchoice { olive = 1, canola = 2, cooking = 3, flavored = 4 };
enum panchoice { standard = 1, deep = 2, hightemp = 3 };
class sicilian : public crust
{
private:
    enum oilchoice oil;
    enum panchoice pan;

public:
    sicilian();
    void setsize(int);
    void setpan(panchoice);
    panchoice getpan()const;
    void setoil(oilchoice);
    oilchoice getoil()const;
    void Hello();
};