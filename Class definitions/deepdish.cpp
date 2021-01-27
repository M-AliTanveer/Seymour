#pragma once
#include <iostream>
#include "deepdish.h"
using namespace std;

deepdish::deepdish()
{
    price = 250;
    size = 6;
    strcpy_s(description, "Deep dish crust contains chilli sauce, or our special sauce to give it its yellow tone, unique taste and texture. Gives a taste of true Chicago DeepDish Pizzas.");
    deep = two;
    sauce = ketchup;
    onions = 0;
    thick = 1;
    thin = 0;
    gluten = 1;
    strcpy_s(name, "DeeepDish");
}
void deepdish::setsize(int s)
{
    size = s;
    price = price + (size - 6) * 70;
}
void deepdish::setthick(thickness h)
{
    deep = h;
    if (deep == twohalf)
        price += 30;
    else if (deep == three)
        price += 60;
}
thickness deepdish::getthick()const
{
    return deep;
}
void deepdish::setsauce(sauces c)
{
    sauce = c;
    if (sauce == chilli)
        price += 20;
    else if (sauce == special)
        price += 50;

}
sauces deepdish::getsauce() const
{
    return sauce;
}
bool deepdish::getonions() const
{
    return onions;
}
void deepdish::setonions(bool g)
{
    onions = g;
    if (onions == true)
        price += 10;
}