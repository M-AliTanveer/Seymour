#pragma once
#include <iostream>
#include "sicilian.h"
using namespace std;

sicilian::sicilian()
{
    price = 250;
    size = 6;
    strcpy_s(description, "Sicilian pizza is known for its thick, rectangle-shaped crust . Baked to a state giving it an almost fried texture");
    oil = olive;
    pan = standard;
    thick = 1;
    thin = 0;
    gluten = 1;
    strcpy_s(name, "Sicilian");

}
void sicilian::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 60;
}
void sicilian::setoil(oilchoice h)
{
    oil = h;
    if (oil == canola)
        price += 10;
    else if (oil == flavored)
        price += 25;
}
oilchoice sicilian::getoil() const
{
    return oil;
}
void sicilian::setpan(panchoice c)
{
    pan = c;
    if (pan == deep)
        price += 20;
    else if (pan == hightemp)
        price += 40;

}
panchoice sicilian::getpan() const
{
    return pan;
}
