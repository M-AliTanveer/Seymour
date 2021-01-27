#pragma once
#include <iostream>
#include "crust.h"
using namespace std;

enum coating { oliveoil = 1, scentedoil = 2, flavoured = 3 };
class focacia : public crust
{
private:
    enum herbs herb;
    enum coating coat;

public:
    focacia();
    void setsize(int);
    void setherbs(herbs);
    herbs getherbs()const;
    void setcoating(coating);
    coating getcoating()const;
    void Hello();
};