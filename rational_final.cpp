#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <exception>
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
	  if(b == 0){
		  throw invalid_argument("");
	  }
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
Rational operator+(const Rational& a, const Rational& b){
	  return Rational(a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator());
 }
Rational operator-(const Rational& a, const Rational& b){
	  return Rational(a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator());
 }
Rational operator/(const Rational& a, const Rational& b){
	  if(b.Numerator() == 0){
		  throw domain_error("");
	  }
	  return Rational(a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator());
 }
Rational operator*(const Rational& a, const Rational& b){
	  return Rational(a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator());
 }
istream& operator>>(istream& stream, Rational& b){
	  int x, y;
	  if(stream)
		  stream >> x;
	  stream.ignore(1);
	  if(stream){
		  stream >> y;
		  b = Rational(x, y);
	  }
	  return stream;
 }
ostream& operator<<(ostream& stream,const Rational& b){
	  stream << b.Numerator() << '/' << b.Denominator();
	  return stream;
 }
 bool operator==(const Rational& a, const Rational& b){
	  if(a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator()){
		  return true;
	  }else{
		  return false;
	  }
 }
 bool operator<(const Rational& a, const Rational& b){
	  if(a.Numerator() * b.Denominator() < b.Numerator() * a.Denominator()){
		  return true;
	  }else{
		  return false;
	  }
 }

