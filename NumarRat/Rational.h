#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

class Rational {
	//atribute
	int a, b;
public:
	//constructori
	Rational(int x = 1, int y = 1);
	Rational(const Rational&);
	explicit Rational(const char*); //constructor pentru conversie

	//metode
	int getNumarator();
	void setNumarator(int);
	int getNumitor();
	void setNumitor(int);

	//supraincarcare de operatori
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);

	static int cmmdc(int a, int b);
	void simplificare();
	friend ostream& operator<<(ostream& os, const Rational&);
	friend istream& operator>>(istream& is, Rational&);

};