#include<iostream>
//#define STRAT_POINT
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRAT_POINT
	std::cout << "hello oop" << std::endl;

	int a;  // ���������� ���������� � ���� ���
	point a;  //���������� ���������� � ���� point
			//�������� ���������� � ��������� point
			//���������� ���������� � ��������� point

	a.x = 2;
	a.y = 3;
	std::cout << a.x << "\t" << a.y << std::endl;

	point* pa = &a;
	std::cout << pa->x << "\t" << pa->y << std::endl;
#endif // STR

	Point A;
	A.set_x(2);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;

}