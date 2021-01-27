#pragma once
#include <iostream>
#include "italian.h"
using namespace std;

italian::italian()
{
    price = 200;
    size = 6;
    strcpy_s(description, "A perfectly thin crispy and delightful crust infused with the herbs of your choice. Crispy and crunchy but not too brittle.");
    herb = none;
    cook = oven;
    thick = 0;
    thin = 1;
    gluten = 0;
    strcpy_s(name, "Italian");
}
void italian::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 40;
}
void italian::setherbs(herbs h)
{
    herb = h;
    if (herb != none)
        price += 20;
}
herbs italian::getherbs()const
{
    return herb;
}
void italian::setcookstyle(cookstyle c)
{
    cook = c;
    if (cook == wood_fired)
        price += 50;
    else if (cook == pan)
        price += 25;

}
cookstyle italian::getcookstyle()const
{
    return cook;
}