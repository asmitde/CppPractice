#include <iostream>

class Complex
{
private:
	double x, y;

public:
	Complex(double r, double i);
	Complex(double c);
	
	double getReal();
	double getImaginary();

	Complex operator+(Complex &c);
	friend Complex operator+(double d, Complex &c);
	friend Complex operator+(Complex &c, double d);

	Complex operator-(Complex &c);
	friend Complex operator-(double d, Complex &c);
	friend Complex operator-(Complex &c, double d);

	Complex operator*(Complex &c);
	friend Complex operator*(double d, Complex &c);
	friend Complex operator*(Complex &c, double d);

	Complex operator/(Complex &c);
	friend Complex operator/(double d, Complex &c);
	friend Complex operator/(Complex &c, double d);

	Complex conjugate();

	friend std::ostream &operator<<(std::ostream &coutput, Complex &c);
	friend std::istream &operator>>(std::istream &cinput, Complex &c);
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

Complex operator+(Complex &c, double d)
{
	Complex csum;
	csum.x = c.x + d;
	csum.y = c.y;
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

Complex operator-(Complex &c, double d)
{
	Complex cdiff;
	cdiff.x = c.x - d;
	cdiff.y = c.y;
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

Complex operator*(Complex &c, double d)
{
	Complex cprod;
	cprod.x = c.x * d;
	cprod.y = c.y * d;
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

Complex operator/(Complex &c, double d)
{
	Complex cquot;
	cquot.x = c.x / d;
	cquot.y = c.y / d;
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