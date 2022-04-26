//Triangle.cpp
#include "Triangle.h"

Triangle::Triangle()
	:Triad()
{
}

Triangle::Triangle(const double a, const double b, const double c)
{
	if (a + b > c && b + c > a && a + c > b)
	{
		set_a(a); set_b(b); set_c(c);
	}
	else
	{
		set_a(0); set_b(0); set_b(0);
	}
}

Triangle::Triangle(const Triangle& v)
	:Triad(v)
{
}

Triangle& Triangle::operator++()
{
	this->set_a(this->get_a() + 1);
	return *this;
}

Triangle& Triangle::operator--()
{
	 this->set_a(this->get_a() - 1);
	return *this;
}

Triangle Triangle::operator++(int)
{
	Triangle a(*this);
	this->set_a(this->get_a() + 1);
	return a;
}

Triangle Triangle::operator--(int)
{
	Triangle a(*this);
	this->set_a(this->get_a() - 1);
	return a;
}

double Triangle::Sum()
{
	return get_a() + get_b() + get_c();
}

double Triangle::Square() const
{
	double a = get_a();
	double b = get_b();
	double c = get_c();
	double S = 0;

	if (a == 0 || b == 0 || c == 0)
	{
		cout << "Square of triangle doesn't exists" << endl;
	}
	else
	{
		double p = (a + b + c) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	return S;
}

void Triangle::Angle(double& A, double& B, double& C) const
{
	const double PI = atan(1) * 4;
	double a = get_a();
	double b = get_b();
	double c = get_c();

	double S = Square();

	if (a == 0 || b == 0 || c == 0)
	{
		cout << "Triangle doesn't exists" << endl;
	}
	else
	{
		double sinA = (S * 2) / (a * b);
		double x1 = asin(sinA);
		A = (x1 * 180) / PI;

		double sinB = (sinA * b) / c;
		double x2 = asin(sinB);
		B = (x2 * 180) / PI;

		C = 180 - (A + B);
	}
}
