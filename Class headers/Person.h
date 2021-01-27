#ifndef PERSON
#define PERSON
#include <iostream>
using namespace std;
enum Gender { Male = 1, Female = 2, Other = 3 };
class Person
{
protected:
    char name[20];
    char Fath_Name[20];
    int age;
    Gender gender;

public:
    Person();
    ~Person();
    bool setname(string);
    bool setF_Name(string);
    bool setage(int);
    void setGender(Gender);
    char* getname();
    char* getF_Name();
    int getage()const;
    Gender getGender()const;
};
#endif