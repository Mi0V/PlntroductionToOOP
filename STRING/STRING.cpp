#include <iostream>
#include <string.h>
using namespace std;

#define WIDTH 22

STRIN operator+(STRIN& one, STRIN& two);
class STRIN
{
	size_t size;
	char* str;

public:

	


	explicit STRIN(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;
	}

	STRIN(const char* str)
	{
		this->size = strlen(str) + 1;

		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout.width(WIDTH);
		cout << std::left << "Const:" << this << endl;
	}

	STRIN(const STRIN& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.size;
		}
		cout.width(WIDTH);
		cout << std::left << "CopyConstructor:" << this << endl;
	}

	~STRIN()
	{
		delete[] this->str;
		cout.width(WIDTH);
		cout << std::left << "destructor" << this << endl;
	}

	//Metods

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}


};

void main()
{
	setlocale(LC_ALL, "");
	STRIN str1;
	str1.print();

	STRIN str2 = "Hello";
	str2.print();

	STRIN str3 = "World";
	str3.print();

	STRIN str4 = str2 + str3;

	cout << typeid("Hello").name() << endl;

}

STRIN operator+(STRIN& one, STRIN& two)
{
	
}