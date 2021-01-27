#pragma once
#include <iostream>
#include "newyork.h"
using namespace std;

newyork::newyork()
{
    price = 240;
    size = 6;
    mineralized = 0;
    strcpy_s(description, "New York-style crust is crispy on the outside, yet soft and pliable enough to fold the slices in half. High Gluten content");
    herb = none;
    thick = 0;
    thin = 1;
    gluten = 1;
    strcpy_s(name, "Newyork");

}
void newyork::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 40;
}
void newyork::setherbs(herbs h)
{
    herb = h;
    if (herb != none)
        price += 20;
}
herbs newyork::getherbs() const
{
    return herb;
}
void newyork::setmineralized(bool b)
{
    mineralized = b;
    if (mineralized == true)
        price += 60;
}
bool newyork::getmineralized() const
{
    return mineralized;
}