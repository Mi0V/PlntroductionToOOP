#include <iostream>
#include <string.h>
using namespace std;


class STRIN
{
	string strg;
	string all_str;
public:

	//geters and seters
	string get_str()const
	{
		return strg;
	}
	void set_str(string str)
	{
		this->strg = str;
	}
	string get_all_str()const
	{
		return all_str;
	}
	void set_all_str(string all_str)
	{
		this->all_str = all_str;
	}

	//constructors

	STRIN()
	{
		this->strg = strg;
		set_str(strg);
		cout << "def const" << endl;
	}

	~STRIN()
	{
		cout << "destructor" << endl;
	}

	//Metods

	void print(STRIN obj)
	{
		cout << obj.get_str() << endl;
	}

};

void main()
{
	string reg = "str";
	setlocale(LC_ALL, "rus");
	STRIN str1 = "Hello";
	STRIN str2 = "World";
	STRIN str3 = str1 + str2;
	cout << str3 << endl;
}

STRIN operator+(STRIN right, STRIN left)
{
	STRIN all;
	right.set_all_str(right.get_str() + left.get_str());

}

ostream& operator<<(ostream& os, STRIN& obj)
{
	os << obj.get_all_str();
}