#include "seekh_kebab.h"
#include<iostream>
bool seekh_kebab::gluten = true;
int seekh_kebab::count = 0;
seekh_kebab::seekh_kebab()
{
    price = 1400;
    strcpy_s(description , "Topped with seekh kabab chunks on tantalizing blend of spicy chicken, onions capsicum, green pepper and cheese. Contains gluten in significant amounts");
    strcpy_s(name ,"seekh kebab");
    count++;
}
bool seekh_kebab::get_gluten()
{
    return gluten;
}

bool seekh_kebab::get_beef() const
{
    return beef;
}
bool seekh_kebab::get_lamb()
{
    return lamb;
}
void seekh_kebab::set_beef(bool B)
{
    beef = B;
}
void seekh_kebab::set_lamb(bool B)
{
    lamb = B;
}
char* seekh_kebab::get_Addon()
{
    if (lamb == true)
    {
        return "Lamb";
    }
    else if (beef == true)
    {
        return "Beef";
    }
    else
    {
        return 0;
    }
}
double seekh_kebab::set_meat(char choice[30])
{
    char CHOICE[30];
    strcpy_s(CHOICE, choice);
    int i;
    //make sure every character in the user input is uppercase
    for (i = 0; i <= 30; i++)
    {
        if (CHOICE[i] >= 'a' && CHOICE[i] <= 'z')
        {
            CHOICE[i] = CHOICE[i] - 32;
        }
    }
    if (strcmp(CHOICE,"LAMB")==0)
    {
        lamb = true;
        price += 105;
        return 0;
    }
    else if (strcmp(CHOICE, "BEEF") == 0)
    {
        beef = true;
        price += 90;
        return 0;
    }
    else
    {
        return 1;
    }
}