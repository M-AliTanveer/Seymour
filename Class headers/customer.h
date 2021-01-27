#pragma once
#include "Person.h"
#include "security.h"
#include "Order.h"
#include <string>
using namespace std;
class customer : public Person, public secured
{
	Order previous[5];
	char username[15];
	char password[30];
	char email[30];
	int saved;
	bool guest;
	int Current_Pos;
	double total_amount; //total amount spent

public:
	customer();
	Order* getprevious();
	void setprevious(Order);
	char* getusername();
	bool setusername(string);
	char* getpassword();
	bool setpassword(string);
	int getCurrentPos()const;
	void SaveChanges();
	char* getemail();
	bool setemail(string);
	bool import(string,string);
	bool getguest()const;
	void setguest(bool);
	bool checkavailable(string);
	void writetofile();
	customer operator+(double);
	double gettotalamount()const;
};

