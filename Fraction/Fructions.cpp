#include <iostream>

using namespace std;

class Fructions
{
	double x;
	double y;
	double z;

public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	double get_z() const
	{
		return z;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_z(double z)
	{
		this->z = z;
	}
	
	Fructions(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;

	}
	~Fructions()
	{

	}

	double fruct(Fructions&)
	{
		
		double division = get_x() / get_y();
		return division;
	}


};

void main()
{
	double x;
	double y;
	setlocale(LC_ALL, "rus");
	cout << "Деление "; cin >> x; cout << "На ";  cin >> y;
	Fructions One;
	One.set_x(x);
	One.set_y(y);
	cout << "Ответ: " << One.fruct(One);


}