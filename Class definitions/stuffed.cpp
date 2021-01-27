#pragma once
#include <iostream>
#include "stuffed.h"
using namespace std;

stuffed::stuffed()
{
    price = 270;
    size = 6;
    strcpy_s(description, "Stuffed crust has cheese of your favourite type added into the crust! The piece that’s actually best enjoyed crust side first! ");
    layer = single;
    cheese = cheddar;
    fill = edge;
    thick = 1;
    thin = 0;
    gluten = 1;
    strcpy_s(name, "Stuffed");

}
void stuffed::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 60;
}
void stuffed::setcheese(cheesetype h)
{
    cheese = h;
    if (cheese == american)
        price += 10;
}
cheesetype stuffed::getcheese() const
{
    return cheese;
}
void stuffed::setfilling(filling c)
{
    fill = c;
    if (fill == base)
        price += 50;
    else if (fill == whole)
        price += 80;

}
filling stuffed::getfilling() const
{
    return fill;
}
void stuffed::setlayer(layering b)
{
    layer = b;
    if (layer == thincut)
        price -= 20;
    else if (layer == doubled)
        price += 50;
}
layering stuffed::getlayer() const
{
    return layer;
}
