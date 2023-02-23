#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <string>

using namespace std;


class fraccion {
private:
	int num;
	int den; 
	int mcd(int a, int b) {
		if (b == 0)
			return a;
		else
			return mcd(b, a%b);
	}
	int abs(int n) {
		if (n >= 0)
			return n;
		else
			return -n;
	}
public:
	// constructora
	fraccion(int n=0, int d = 1) {
		if (d!=0) {
			if (n == 0) {
				num = 0;
				den = 1;
			}
			else {//Ambos distintos de cero
				int maxcd = mcd(n, d);
				if (d > 0 && n > 0) {
					num = n / maxcd;
					den = d / maxcd;
				}
				else if (d < 0 && n < 0) {
					num = abs(n / maxcd);
					den = abs(d / maxcd);
				}
				else {//El signo lo lleva el numerador
					num = -abs(n / maxcd);
					den = abs(d / maxcd);
				}

			}
			
		}
		else {
			throw std::domain_error("datos invalidos");
		}
	}

	// operadores
	bool operator==(fraccion const& frac2) const {
		return this->num*frac2.den == this->den*frac2.num;
	}
	bool operator!=(fraccion const& frac2) const {
		return !(*this == frac2);
	}
	bool operator<(fraccion const& frac2) const {
		return this->num*frac2.den < this->den*frac2.num;
	}
	bool operator<=(fraccion const& frac2) const {
		return this->num*frac2.den <= this->den*frac2.num;
	}
	bool operator>(fraccion const& frac2) const {
		return this->num*frac2.den > this->den*frac2.num;
	}
	bool operator>=(fraccion const& frac2) const {
		return this->num*frac2.den >= this->den*frac2.num;
	}
	fraccion operator+(fraccion const& frac2) const {
		return fraccion(this->num*frac2.den+ this->den*frac2.num, this->den*frac2.den);
	}
	fraccion operator-(fraccion const& frac2) const {
		return fraccion(this->num*frac2.den - this->den*frac2.num, this->den*frac2.den);
	}
	fraccion operator*(fraccion const& frac2) const {
		return fraccion(this->num*frac2.num, this->den*frac2.den);
	}
	fraccion operator/(fraccion const& frac2) const {
		if(frac2.num!=0)
			return fraccion(this->num*frac2.den, this->den*frac2.num);
		else
			throw std::domain_error("datos invalidos");
	}

	void read(std::istream & input = std::cin) {
		double c;
		input >> c;
		*this = fraccion((int)100*c, 100);
			
	}
	void print(std::ostream& o = std::cout) const {
		string s;
		if (den != 1) {
			s = to_string(num) + "/" + to_string(den);
			o << setw(7 + (s.length() - 1) / 2) << right << setfill(' ') << s << ' ';
		}
		else {
			s = to_string(num);
			o << setw(7 + (s.length() - 1) / 2) << right << setfill(' ') << s << ' ';
		}
		for (int i = 0; i < 3 - (s.length()-1) / 2; i++)
			o << ' ';
	}

};

