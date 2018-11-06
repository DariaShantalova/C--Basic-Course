#include <iostream>
using namespace std;

class Rational {
public:
  Rational() {
	  num = 0;
	  den = 1;
  }
  Rational(int numerator, int denominator){
	  int a = numerator;
	  int b = denominator;
	  if(a < 0){
		  a *= -1;
	  }
	  if(b < 0){
		  b *= -1;
	  }

	  while(a > 0 && b > 0) {
		  if(a > b) {
			  a %= b;
		  }else {
			  b %= a;
		  }
	  }
	  num = numerator / (a + b);
	  den = denominator / (a + b);
	  if(den < 0){
		  num = (-1) * num;
		  den = (-1) * den;
	  }
	  if(numerator == 0){
		  num = 0;
		  den = 1;
	  }
  }

  int Numerator() const{
	  return num;
  }
  int Denominator() const {
	  return den;
  }
private:
  int num;
  int den;
};

