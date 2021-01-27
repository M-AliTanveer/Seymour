#pragma once
#include <iostream>
#include "crust.h"
using namespace std;

enum thickness { two = 1, twohalf = 2, three = 3 };
enum sauces { ketchup = 1, chilli = 2, special = 3 };
class deepdish : public crust
{
private:
    enum thickness deep;
    enum sauces sauce;
    bool onions;

public:
    deepdish();
    void setsize(int);
    void setthick(thickness);
    thickness getthick()const;
    void setsauce(sauces);
    sauces getsauce()const;
    bool getonions()const;
    void setonions(bool);
};