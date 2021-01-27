#pragma once
#include <iostream>
#include "focacia.h"
using namespace std;

focacia::focacia()
{
    price = 230;
    size = 6;
    strcpy_s(description, "This olive-oil soaked Italian bread is deliciously topped with sun-dried tomatoes or olives or other herbs of your choice");
    herb = onions;
    coat = oliveoil;
    thin = 0;
    thick = 1;
    gluten = 1;
    strcpy_s(name, "Focacia");

}
void focacia::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 60;
}
void focacia::setherbs(herbs h)
{
    herb = h;
    if (herb == garlic)
        price += 10;
    else if (herb == scallion)
        price += 15;
    else if (herb == garlicpowder)
        price += 15;
}
herbs focacia::getherbs()const
{
    return herb;
}
void focacia::setcoating(coating c)
{
    coat = c;
    if (coat == scentedoil)
        price += 30;
    else if (coat == flavoured)
        price += 40;

}
coating focacia::getcoating() const
{
    return coat;
}