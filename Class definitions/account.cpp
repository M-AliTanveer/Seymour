#pragma once
#pragma warning(disable: 6262)

#include "customer.h"
#include <fstream>

using namespace std;
customer::customer()
{
	saved = 0;
	strcpy_s(username, "");
	strcpy_s(password, "");
	strcpy_s(email, "");
	strcpy_s(address, "");
	contactno = 0;
	guest = false;
	total_amount = 0;
}
Order* customer::getprevious()
{
	return previous;
}
void customer::setprevious(Order newest)
{

	for (int i = 4; i > 0; i--)
	{
		previous[i] = previous[i - 1];
	}
	previous[0] = newest;
}
char* customer::getusername()
{
	return username;
}
bool customer::setusername(string s)
{
	try {
		if (s.length()>=6 && s.length() < 15 && checkavailable(s))
		{
			strcpy_s(username, s.c_str());
			return true;
		}
		else
			throw 1;

	}
	catch (int)
	{
		strcpy_s(username, "");
		return false;
	}
}
char* customer::getpassword()
{
	return password;
}
bool customer::setpassword(string p)
{
	try {
		if (p.length() >= 8 && p.length() < 30)
		{
			strcpy_s(password, p.c_str());
			return true;
		}
		else
			throw 1;
	}
	catch (int)
	{
		strcpy_s(password, "");
		return false;
	}
}
char* customer::getemail()
{
	return email;
}
bool customer::setemail(string s)
{
	s == "" ? (s = "               ") : ("");
	try {
		int n = int(s.length());
		if (s[n-1] == 'm' && s[n - 2] == 'o' && s[n - 3] == 'c' && s[n - 4] == '.' && (s[n - 10] == '@' || s[n - 12] == '@') && n < 30)
		{
			strcpy_s(email, s.c_str());
			return true;
		}
		else
			throw 1;

	}
	catch (int)
	{
		strcpy_s(email, "radomemail@gmail.com");
		return false;
	}
}
bool customer::import(string user, string pass)
{
	customer temp;
	bool val=false;
	fstream accountsfile("accountdata.dat", ios::in | ios::binary);
	for (; accountsfile.read((char*)&temp, sizeof(temp)) ;)
	{
		if (temp.getusername() == user && temp.getpassword() == pass)
		{
			val = true;
			*this = temp;
			Current_Pos = int(accountsfile.tellg())/int(sizeof(customer));
			break;
		}

	}

	accountsfile.close();
	return val;
}
bool customer::getguest()const
{
	return guest;
}
void customer::setguest(bool b)
{
	guest = b;
}
bool customer::checkavailable(string a)
{
	customer temp;
	fstream accountsfile("accountdata.dat", ios::in | ios::binary);
	for (;1;)
	{
		if (accountsfile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getusername() == a || (a.length() < 6 || a.length() > 15))
			{
				return false;
			}
		}
		else
		{
			if ((a.length() < 6 || a.length() > 15))
			{
				return false;
			}
			else
				break;
		}
	}
	accountsfile.close();
	return true;
}
void customer::writetofile()
{
	fstream accountsfile("accountdata.dat", ios::out |ios::app | ios::binary);
	accountsfile.write((char*)&*this, sizeof(*this));
	accountsfile.close();
}
int customer::getCurrentPos()const
{
	return Current_Pos;
}
void customer::SaveChanges()
{
	fstream AccountFile;
	AccountFile.seekg(Current_Pos*sizeof(customer));
	AccountFile.open("accountdata.dat", ios::out | ios::binary);
	AccountFile.write(reinterpret_cast<char*>(&*this), sizeof(*this));
}
double customer::gettotalamount() const
{
	return total_amount;
}
customer customer::operator +(double b)
{
	total_amount = total_amount + b;
	return *this;
}