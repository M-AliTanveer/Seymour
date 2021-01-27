#pragma once
#include "crust.h"
using namespace std;

class newyork : public crust
{
private:
    enum herbs herb;
    bool mineralized;

public:
    newyork();
    void setsize(int);
    void setherbs(herbs);
    herbs getherbs()const;
    void setmineralized(bool);
    bool getmineralized()const;
    void Hello();
};