#pragma once
#include "security.h"
#include <iostream>
#include <string>
using namespace std;


int digitcounter(long long int v)
{
	int count = 0;
	for (; v != 0;)
	{
		v = v / 10;
		count++;
	}
	return count;
}

secured::secured()
{
	contactno = 0;
	cnic = 0;
	//strcpy_s(address, "");
	cod = true;
	strcpy_s(card, "");
	cardno = 0;
	monthc = 0;
	yearc = 0;
}

bool secured::setcontact(long long int c)
{
	try {
		int i=0;
		if (digitcounter(c)==10)
		{
			contactno = encryption(c);
			return true;
		}
		else 
			throw i++;
	}
	catch (int i) {
		i > 0 ? (contactno = 0) : (1);
		return false;
	}
}
long long int secured::getcontact()
{
	return decryption(contactno);
}
bool secured::setcnic(long long int c)
{	
	int i=0;
	try {
		
		if (digitcounter(c)==10)
		{
			cnic = encryption(c);
			return true;
		}
		else
			throw i++;
	}
	catch (int i) {
		i > 0 ? (cnic = 0) : (1);
		return false;
	}
}
long long int secured::getcnic()
{
	return decryption(cnic);
}
void secured::setaddress(string s)
{
	strcpy_s(address,(encryption(s)).c_str());
}
char* secured::getaddress()
{
	return decryption(address);
	
}
void secured::setpaymentttype(bool b)
{
	cod = b;
}
bool secured::getpaymenttype()const
{
	return cod;
}
void secured::setcardprovider(string s)
{
	strcpy_s(card, (encryption(s)).c_str());
}
char* secured::getcardprovider()
{
	return decryption(card);
}
bool secured::setcardno(long long int i)
{
	int o=0;
	try {
		if (digitcounter(i) == 9 || i == 0 )
		{
			cardno = encryption(i);
			return true;
		}
		else
			throw o++;
	}
	catch (int o) {
		o > 0 ? (cardno = 0) : (1);
		return false;
	}
}
long long int secured::getcardno()
{
	return decryption(cardno);
}
bool secured::setexpiry(int m, int y)
{
	try {
		int i=0;
		if ((m>5 && m<13 && y > 2019) || (m==0 && y==0))
		{
			monthc = encryption(m);
			yearc = encryption(y);
			return true;
		}
		else
			throw i++;
	}
	catch (int i) {
		i > 0 ? (monthc = 5, yearc = 2020) : (1);
		return false;
	}
}
int* secured::getexpiry()
{
	static int exp[2];
	exp[0] = decryption(monthc);
	exp[1] = decryption(yearc);
	return exp;
}
template <typename encrypt>
encrypt secured::encryption(encrypt var)
{
	encrypt temp, temp2 = 0;
	temp = var;

	for (int i = 0; temp != 0; i++)
	{
		temp2 = temp2 * 10 + (temp % 10);
		temp = temp / 10;

	}
	return temp2;
}
template <typename encrypt>
encrypt secured::decryption(encrypt var)
{
	encrypt temp, temp2 = 0;
	temp = var;
	for (int i = 0; temp != 0; i++)
	{
		temp2 = temp2 * 10 + (temp % 10);
		temp = temp / 10;
	}
	return temp2;
}
string secured::encryption(char* var)
{
	string temp = var;
	return encryption(temp);
}
char* secured::decryption(char* var)
{
	string temp = var;
	return decryption(temp);
}
string secured::encryption(string var)
{
	string temp = var;
	int i, length = static_cast<int>(temp.length());
	for (i = 0; i < length ; i++)
	{
		if (i % 2 == 0)
			temp[i] = temp[i] + 2;
		else if (i % 2 == 1)
			temp[i] = temp[i] - 2;
	}
	//temp[length] = '\0';
	return temp;
}
char* secured::decryption(string var)
{
	int n = static_cast<int>(var.length());
	char* temp = new char[n+1];
	var.copy(temp, n);
	int i, length = static_cast<int>(strlen(temp));
	for (i = 0; i < length; i++)
	{
		if (i % 2 == 0)
			*(temp + i) = *(temp + i) - 2;
		else if (i % 2 == 1)
			temp[i] = (temp[i] + 2);
	}
	temp[n] = '\0';
	return temp;
}


