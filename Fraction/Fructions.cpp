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
		cout << "Расчет числителя: " << mas(x,y) << endl;
		cout << "Знаменатель: "; cin >> this->y;
		double division = get_z() / get_y();
		return division;
	}

	double mas(double x, double y)
	{
		double all = 0;
		int a = 0;
		int SIZE = 5;
		int* arr = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{


			cin >> arr[i];
			all += arr[i];
			set_z(all);


			/*if (arr[i] == 1000)
			{
				cin >> arr[i];
				a = arr[i];
				all += arr[i];
				set_z(all);
			}
			else
			{
				SIZE++;
				cin >> arr[i];
				all += arr[i];
				set_z(all);
			}*/
			
		}
		delete[] arr;
		return all;


	}


};

void main()
{
	double x;
	double y;
	setlocale(LC_ALL, "rus");
	Fructions One;
	cout << "Ответ: " << One.fruct(One);


}