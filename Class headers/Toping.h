#ifndef TOPING
#define TOPING

#include <iostream>
using namespace std;


class Toping
{
protected:
    int price;
    char details[300];
    char name[200];

public:
    Toping();
    void setprice(int);
    int getprice(void)const;
    void setdetails(char[]);
    char* getdetails();
    char* getToppingName();
    void increaseprice(int size);

};
#endif