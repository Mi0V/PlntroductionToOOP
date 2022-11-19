#include<iostream>
//#define STRAT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTIONS_CHECK
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

	//constructor:
	//Point()
	//{
	//	x = y = double(); //Значение по умолчанию дял double
	//	std::cout << "Constructor:\t" << this << std::endl;
	//}
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	std::cout << "LargConstructor" << this << std::endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "LargdConstructor" << this << std::endl; // Строчку с выводом конструктора можно просто удалить, 
														  //дабы глазу не мешал, но оставил для наглядности.
	}
	Point(const Point& other)	
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor: " << this << std::endl; 
	}

	~Point()
	{
		std::cout << "Destructor:\t" << this << std::endl;// Строчку с выводом диструктора можно просто удалить, 
														  //дабы глазу не мешал, но оставил для наглядности.
		
	}

	//  Metods:
	double distance(Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		std::cout << "x = " << x << "\tY = " << y << std::endl;
	};
};

double distance(Point& A, Point& B)		// Ссылки позволяют убрать лишнее
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}


void main()
{
	setlocale(LC_ALL, "");
#ifdef STRAT_POINT
	std::cout << "hello oop" << std::endl;

	int a;  // объявление переменной а типа инт
	point a;  //объявление переменной а типа point
			//создание экземпляра а структуры point
			//объявление экземпляра а структуры point

	a.x = 2;
	a.y = 3;
	std::cout << a.x << "\t" << a.y << std::endl;

	point* pa = &a;
	std::cout << pa->x << "\t" << pa->y << std::endl;
#endif // STRAT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	std::cout << "Расстояние  от точки А до точки В = " << A.distance(B) << std::endl;
	std::cout << "Расстояние  от точки А до точки В = " << B.distance(A) << std::endl;
	std::cout << "Расстояние между точками А и В = " << distance(A, B) << std::endl;
	std::cout << "Расстояние между точками А и В = " << distance(A, B) << std::endl;

#endif // DISTANCE_CHECK

#ifdef CONSTRUCTIONS_CHECK

	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(8);
	C.print();

	Point D(5, 8);
	D.print();

	Point E = D; //Copy constructor
	E.print();
#endif // CONT


}