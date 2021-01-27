#pragma once
#include <iostream>
#include "crust.h"
using namespace std;

class stlouis : public crust
{
private:
    bool cheese;
    bool tavern;

public:
    stlouis();
    void setsize(int);
    void setcheese(bool);
    bool getcheese()const;
    bool gettavern()const;
    void settavern(bool);
    void Hello();
};