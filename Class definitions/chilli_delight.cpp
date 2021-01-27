#include "chilli_delight.h"
#include<iostream>
#include<string>
bool::chilli_delight::gluten = false;
int chilli_delight::count = 0;
chilli_delight::chilli_delight()
{
    price = 1100;
    strcpy_s(description, "Fire up your taste buds with spicy chicken chunks, onions, olives, jalapenos and hot peri sauce. Gluten free.");
    chicken = true;
    strcpy_s(name,"chilli delight");
    count++;
    red = false;
    green = false;
}
bool chilli_delight::get_gluten()
{
    return gluten;
}
double chilli_delight::set_chilli(char* choice)
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
    if (strcmp(CHOICE,"RED")==0)
    {
        red = true;
        green = false;
        price += 40;
        return 0;
    }
    else if (strcmp(CHOICE, "GREEN") == 0)
    {
        green = true;
        red = false;
        price += 80;
        return 0;
    }
    else {
        return 0;
    }
}
char* chilli_delight::get_Addon() 
{
    if (green == true)
    {
        return "Green Chilli";

    }
    else if (red == true)
    {
        return "Red Chilli";
    }
    else
    {
        return 0;
    }
}