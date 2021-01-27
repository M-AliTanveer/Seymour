#pragma once
#include "crust.h"
//using namespace std;

class neapolitan : public crust
{
private:
    enum cookstyle cook;
    bool essence;               //sunflower oil essencce
    bool hand;

public:
    neapolitan();
    void setsize(int);
    void setessence(bool);
    bool getessence()const;
    void sethand(bool);
    bool gethand()const;
    void setcookstyle(cookstyle);
    cookstyle getcookstyle()const;
    void Hello();
};

