#pragma once
#include <iostream>
#include "stlouis.h"
using namespace std;

stlouis::stlouis()
{
    price = 230;
    size = 6;
    strcpy_s(description, "The St. Louis crust. A cheese lining on the crust and a very non palliable crunchy texture referred to as cracker like");
    tavern = 1;
    cheese = 0;
    thick = 0;
    thin = 1;
    gluten = 0;
    strcpy_s(name, "Stlouis");
}
void stlouis::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 45;
}
void stlouis::settavern(bool b)
{
    tavern = b;
}
bool stlouis::gettavern()const
{
    return tavern;
}
void stlouis::setcheese(bool b)
{
    cheese = b;
}
bool stlouis::getcheese() const
{
    return cheese;
}
