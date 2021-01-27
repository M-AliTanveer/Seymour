#include "veggie_delight.h"
#include<iostream>
bool veggie_delight::gluten = false;
int veggie_delight::count = 0;
veggie_delight::veggie_delight()
{
    price = 1000;
    strcpy_s(description , "A colorful medley of tomatoes, onions, mushrooms, black olives, and green peppers. Gluten free");
    gluten = false;
    strcpy_s(name , "Veggie Delight");
    count++;
}
bool veggie_delight::get_gluten()
{
    return gluten;
}

char* veggie_delight::get_Addon()
{
    return 0;
}