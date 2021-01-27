#pragma once
#include <string>
using namespace std;

enum herbs { none = 0, onions = 1, garlic = 2, scallion = 3, garlicpowder = 4 };
enum cookstyle { pan = 1, wood_fired = 2, oven = 3 };
class crust
{
protected:
    double price;
    char description[350];
    int size;
    bool thick, thin, gluten;
    char name[30];
public:
    virtual void setsize(int)=0;
    int getsize()const;
    double get_price()const;
    void set_price(double);
    char*  get_description();
    void set_description(string);
    bool getthickthin()const;
    void setthickthin(bool);
    bool getgluten()const;
    void setgluten(bool);
    char* get_CrustName();
};

