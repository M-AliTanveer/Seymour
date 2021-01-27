#pragma once
#include "flavours.h"
class bbq_buzz :
	public flavour
{
private:
    bool chicken;
    bool bbq_sauce;
    bool ranch;
    static  bool gluten;
    static int count;
public:
    bbq_buzz();
    double set_sauce(char* choice);
    void set_bbq(bool B);
    void set_ranch(bool B);
    void set_chicken(bool B);
    bool get_chicken()const;
    bool get_bbq()const; 
    bool get_ranch()const;
    char* get_Addon();
    static bool get_gluten(); 
};

