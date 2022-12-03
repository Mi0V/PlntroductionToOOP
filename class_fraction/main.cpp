#include <iostream>
using namespace std;
#define WIDTH  32
//#define CONSTRUCTIONS_CHECK
#define CHECK
//#define INCREMENT_CHECK
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);
class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:

	int get_integer() const
	{
		return integer;
	}

	int get_numerator()const
	{
		return numerator;
	}

	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}

	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//constructors 
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;

	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout <<std::left << "SingleArgumentConstructor:" << this << endl;

	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout <<std::left<<"Constructor:" << this << endl;


	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		
		cout <<std::left<< "Constructor:" << this << endl;


	}

	~Fraction()
	{
		cout.width(WIDTH);
		cout<<std::left << "Destructor:" << this << endl;
	}

	//Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyAssignment:" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}



	Fraction& operator++()
	{
		integer++;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}


	//Metods:


	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;

		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD -Greatest Common Divisor 
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void Print()const
	{
		if (integer)cout << integer << " ";
		if (numerator)
		{
			cout << numerator << "/" << denominator;

		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

};

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTIONS_CHECK
	Fraction A;//def
	A.Print();

	Fraction B = 5;//singl
	B.Print();

	Fraction C(1, 2);
	C.Print();

	Fraction D(2, 3, 4);
	D.Print();
	D.to_improper();
	D.Print();
	D.to_proper();
	D.Print();
#endif // CONSTRUCTIONS_CHECK
#ifdef CHECK
	Fraction A(2, 3, 4);
	A.Print();
	Fraction B(3, 4, 5);
	B.Print();
	Fraction C = A / B;
	C.Print();
	A*=B;
	A.Print();
	A /= B;
	A.Print();
	cout << A;
#endif // CHECK


#ifdef INCREMENT_CHECK
	C.Print();
	for (double i = .0325; i < 10, i++)
	{
		cout << i << "\t";

	}
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.Print();
	}
#endif // INCREMENT_CHECK
	/*Fraction A(2, 3, 4);
	cout << A << endl;*/
}
Fraction operator*(Fraction right, Fraction left)
{
	left.to_improper();
	right.to_improper();
	/*Fraction res;
		res.set_numerator(left.get_numerator() * right.get_numerator());
		res.set_denominator(left.get_denominator() * right.get_denominator());
		res.to_proper();*/
	/*Fraction res
		(
			left.get_numerator() * right.get_numerator(),
			left.get_denominator() * right.get_denominator()
		);
		res.to_proper();
		return res;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator()* left.get_denominator()
	).to_proper().reduce();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer() << " ";
	if (obj.get_numerator())
	{
		os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	else os << 0;
	return os;
}
ostream& operator>>(ostream& os, const Fraction& obj, Fraction)
{
	os >> obj.set_integer();
	cout << "/";
	os >> obj.set_numerator();
}