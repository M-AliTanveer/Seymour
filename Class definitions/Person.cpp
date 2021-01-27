#include "Person.h"
#include <string>
#include <stdlib.h>
Person::Person() : name(""), Fath_Name(""), age(0), gender(Male) {}

Person::~Person()
{
    cout << endl;
}

bool Person::setname(string N)
{
    string tempN;
    int i, n = 0;
    for (i = 0; i < N.length(); i++)
    {
        if ((N[i] >= 65 && N[i] <= 90) || (N[i] >= 97 && N[i] <= 122) || N[i] == 32)
        {
            n = 0;
        }
        else
            n++;
    }
    try
    {
        if (n == 0)
        {
            strcpy_s(name,N.c_str());
            return true;
        }
        else throw 1;
    }
    catch (...)
    {
        strcpy_s(name, "");
        return false;
    }

}

bool Person::setF_Name(string FN)
{
    string tempFN;
    int size, i, n = 0;
    size = (int)FN.size();
    for (i = 0; i < size; i++)
    {
        if ((FN[i] >= 65 && FN[i] <= 90) || (FN[i] >= 97 && FN[i] <= 122) || FN[i] == 32)
        {
            n = 0;
        }
        else
            n++;
    }
    try
    {
        if (n == 0)
        {
            strcpy_s(Fath_Name, FN.c_str());
            return true;
        }
        else throw 1;
    }
    catch (...)
    {
        strcpy_s(Fath_Name, "");
        return false;
    }
}

bool Person::setage(int a)
{
    int n = a, c = 0;
    while (n > 0)
    {
        n = n / 10;
        c++;
    }
    try
    {
        if (c == 2)
        {
            age = a;
            return true;
        }
        else throw 1;
    }
    catch (...)
    {
        age = 0;
        return false;
    }
}

void Person::setGender(Gender g)
{
    gender = g;
}

char* Person::getname()
{
    return name;
}

char* Person::getF_Name()
{
    return Fath_Name;
}

Gender Person::getGender() const
{
    return gender;
}

int Person::getage()const
{
    return age;
}

