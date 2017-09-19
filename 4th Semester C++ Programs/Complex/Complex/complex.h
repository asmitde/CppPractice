#include <iostream>

class Complex
{
private:
	double x, y;															// x : real component ; y : imaginary component

public:
	Complex(double r, double i);											// Constructor with initial values
	Complex(double c);														// Constructor with same x & y ; default : 0
	
	double getReal();														// Returns real component
	double getImaginary();													// Returns imaginary component

	Complex operator+(Complex &c);											// Returns Complex + Complex
	friend Complex operator+(double d, Complex &c);							// Returns Complex + real
	Complex operator+(double d);											// Returns real + Complex

	Complex operator-(Complex &c);											// Returns Complex - Complex
	friend Complex operator-(double d, Complex &c);							// Returns Complex - real
	Complex operator-(double d);											// Returns real - Complex

	Complex operator*(Complex &c);											// Returns Complex * Complex
	friend Complex operator*(double d, Complex &c);							// Returns Complex * real
	Complex operator*(double d);											// Returns real * Complex

	Complex operator/(Complex &c);											// Returns Complex / Complex
	friend Complex operator/(double d, Complex &c);							// Returns Complex / real
	Complex operator/(double d);											// Returns real / Complex

	Complex conjugate();													// Returns Complex conjugate

	friend std::ostream &operator<<(std::ostream &coutput, Complex &c);		// Prints a Complex number
	friend std::istream &operator>>(std::istream &cinput, Complex &c);		// Inputs a Complex number
};

Complex::Complex(double r, double i)
{
	x = r;
	y = i;
}

Complex::Complex(double c = 0)
{
	x = y = c;
}

double Complex::getReal()
{
	return x;
}

double Complex::getImaginary()
{
	return y;
}

Complex Complex::operator+(Complex &c)
{
	Complex csum;
	csum.x = x + c.x;
	csum.y = y + c.y;
	return csum;
}

Complex operator+(double d, Complex &c)
{
	Complex csum;
	csum.x = d + c.x;
	csum.y = c.y;
	return csum;
}

Complex Complex::operator+(double d)
{
	Complex csum;
	csum.x = x + d;
	csum.y = y;
	return csum;
}

Complex Complex::operator-(Complex &c)
{
	Complex cdiff;
	cdiff.x = x - c.x;
	cdiff.y = y - c.y;
	return cdiff;
}

Complex operator-(double d, Complex &c)
{
	Complex cdiff;
	cdiff.x = d - c.x;
	cdiff.y = -c.y;
	return cdiff;
}

Complex Complex::operator-(double d)
{
	Complex cdiff;
	cdiff.x = x - d;
	cdiff.y = y;
	return cdiff;
}

Complex Complex::operator*(Complex &c)
{
	Complex cprod;
	cprod.x = x * c.x - y * c.y;
	cprod.y = y * c.x + x * c.y;
	return cprod;
}

Complex operator*(double d, Complex &c)
{
	Complex cprod;
	cprod.x = d * c.x;
	cprod.y = d * c.y;
	return cprod;
}

Complex Complex::operator*(double d)
{
	Complex cprod;
	cprod.x = x * d;
	cprod.y = y * d;
	return cprod;
}

Complex Complex::operator/(Complex &c)
{
	Complex cquot, num, deno;
	deno = c * c.conjugate();
	double d = deno.getReal();
	num = *this * c.conjugate();
	cquot.x = num.x / d;
	cquot.y = num.y / d;
	return cquot;
}

Complex operator/(double d, Complex &c)
{
	Complex cquot, num, deno;
	deno = c * c.conjugate();
	double de = deno.getReal();
	num = d * c.conjugate();
	cquot.x = num.x / d;
	cquot.y = num.y / d;
	return cquot;
}

Complex Complex::operator/(double d)
{
	Complex cquot;
	cquot.x = x / d;
	cquot.y = y / d;
	return cquot;
}

Complex Complex::conjugate()
{
	Complex cconj;
	cconj.x = -x;
	cconj.y = -y;
	return cconj;
}

std::ostream &operator<<(std::ostream &coutput, Complex &c)
{
	coutput<<c.x<<"+i"<<c.y;
	return coutput;
}

std::istream &operator>>(std::istream &cinput, Complex &c)
{
	cinput>>c.x>>c.y;
	return cinput;
}