#include "Rational.h"


Rational::Rational(int a, int b) {
	this->a = a;
	this->b = b;
	simplificare();
}

Rational::Rational(const Rational& x) {
	a = x.a;
	b = x.b;
}

Rational::Rational(const char* str)
{
	char* pos_impartire = (char*)(strrchr)(str, '/');
	if (pos_impartire == NULL)
	{
		a = strtod(str, NULL);
		b = 1;
	}
	else
	{
		a = strtod(str, &pos_impartire);
		b = strtod(pos_impartire + 1, NULL);
	}
	simplificare();
}

int Rational::getNumarator() {
	return a;
}

int Rational::getNumitor() {
	return b;
}

void Rational::setNumarator(int a) {
	this->a = a;
	simplificare();
}

void Rational::setNumitor(int b) {
	this->b = b;
	simplificare();
}


Rational Rational::operator+(const Rational& c) {
	return Rational(a*c.b + b * c.a, b*c.b);
}

Rational Rational::operator-(const Rational& c) {
	return Rational(a*c.b - b * c.a, b*c.b);
}

Rational Rational::operator*(const Rational& c) {
	return Rational(a*c.a, b*c.b);
}

Rational Rational::operator/(const Rational& c) {
	return Rational(a*c.b, b*c.a);
}

int Rational::cmmdc(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else b = b - a;
	}
	return a;
}

void Rational::simplificare()
{
	int d = cmmdc(a, b);
	if (d > 0)
	{
		a /= d;
		b /= d;
	}
}

ostream& operator<<(ostream& out, const Rational& d) {
	if (d.a == 0)out << 0;
	else if (d.b == 1)out << d.a;
	else out << (d.a*d.b < 0 ? "-" : " ") << abs(d.a) << "/" << abs(d.b);
	return out;
};

istream& operator>>(istream& in, Rational& d) {
	in >> d.a >> d.b;
	d.simplificare();
	return in;
}

int main()
{
	Rational r1(5, 3), r2("12/5"), r, radunare, rscadere;
	r = r1 / r2;
	radunare = r + r1;
	rscadere = r2 - r1;
	cout << r1 << " " << r2 << " " << r << endl;
	cout << radunare << " " << rscadere << endl;
	system("pause");
	return 0;
}