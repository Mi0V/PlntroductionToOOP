#include <iostream>

//#define One
//#define Two
#define three

class distance
{
	double a = 0;
	double b = 0;
	double c = 0;
public:
	double get_a()const
	{
		return a;
	}
	double get_b()const
	{
		return b;
	}
	double get_c()const
	{
		return c;
	}
	void set_a(double a)
	{
		this->a = a;
	}
	void set_b(double b)
	{
		this->b = b;
	}
	void set_c(double c)
	{
		this->c = c;
	}
	double dist(double a, double b)
	{
		
		if (get_a() >= get_b()) set_c(get_a() - get_b());
		else set_c(get_b() - get_a());
		return c;

	}
	void print(double a, double b)
	{
		//distance C;
		std::cout << "Enter point A: "; std::cin >> a;
		std::cout << "Enter point B: "; std::cin >> b;
		set_a(a);
		set_b(b);
	}


};
double distances(double a, double b);


void main()
{
#ifdef One
	distance A;
	double a;
	double b;
	std::cout << "Enter point A: "; std::cin >> a;
	std::cout << "Enter point B: "; std::cin >> b;
	A.set_a(a);
	A.set_b(b);
	if (A.get_a() >= A.get_b()) A.set_c(A.get_a() - A.get_b());
	else A.set_c(A.get_b() - A.get_a());

	std::cout << "distance: " << A.get_c();
#endif // One
#ifdef Two
	double a;
	double b;
	std::cout << "Enter point A: "; std::cin >> a;
	std::cout << "Enter point B: "; std::cin >> b;
	std::cout << "distance: " << distances(a, b) << std::endl;
#endif // Two
#ifdef three
	distance B;
	double a = 0;
	double b = 0;
	B.print(a, b);
	std::cout << "distance: " << B.dist(a,b);
}
#endif // three


double distances(double a, double b)
{
	double c;
	if (a >= b) c = a - b;
	else c = b - a;
	return c;
}