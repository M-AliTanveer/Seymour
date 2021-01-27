#include "tikka.h"
#include<iostream>

bool tikka::gluten = false;
int tikka::count = 0;
tikka::tikka()
{
    price = 1259.99;
  
    strcpy_s(description , "A specially developed recipe  topped with spicy  tikka boti & onions. Gluten Free.");
    chicken = true;
    count++;
    strcpy_s(name,"tikka");
}
bool tikka::get_gluten()
{
    return gluten;
}
bool tikka::get_beef() const
{
    return beef;
}
bool tikka::get_chicken() const
{
    return chicken;
}
double tikka::set_beef(bool B)
{
    chicken = false;
    beef = B;
    price += 50;
    return 0;
}
double tikka::set_chicken(bool B)
{
    beef = false;
    chicken = B;
    price += 30;
    return 0;
}
char* tikka::get_Addon()
{
    if (chicken==true)
    {
        return "Chicken";
    }
    else if (beef==true)
    {
        return "Beef";
    }
    else
    {
        return 0;
    }
}