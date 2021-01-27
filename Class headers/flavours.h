#pragma once
class flavour
{
protected:
    double price;
    char description[220];
    char name[30];
public:
    flavour();
    void increaseprice(int size);
    double  get_price() const;
     double  set_price(double PRICE) ;
      char*  get_description();
     char* set_description(char* desc) ;
    char* get_FlavName();
    virtual char* get_Addon() = 0;
};
