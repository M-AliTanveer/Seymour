#ifndef STAFF
#define STAFF
#include "Person.h"

class Staff : public Person
{
protected:
    char Staff_ID[20], Staff_Password[20];
    double salary;
public:
    Staff();
    Staff(int a);
    virtual bool setID(string) = 0;
    bool setPass(string);
    bool virtual check(string, string) = 0;
    void setsalary(double);
    char* getID();
    char* getPass();
    double getsalary()const;
};
#endif