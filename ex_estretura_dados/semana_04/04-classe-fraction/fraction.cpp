#include <iostream>
#include <cmath>
//#include "fraction_aux.h"

using namespace std;

class Fraction{
    public:
       Fraction();
       Fraction(int num,int den);

       int numerator() const;
       int denominator() const;

       Fraction sum(const Fraction& right) const;
       Fraction sub(const Fraction& right) const;
       Fraction mul(const Fraction& right) const;
       Fraction div(const Fraction& right) const;

       void write() const;
       void normalise();
       int gcd(int a, int b);

    
    private:
        int numerator_;
        int denominator_;
};


int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}

void Fraction::write() const {
  cout << numerator_ << '/' << denominator_;
}

Fraction::Fraction(){
    numerator_ = 0;
    denominator_ = 1;
}

Fraction::Fraction(int n, int d){
    numerator_ = n;
    denominator_ = d;
    
    Fraction::normalise();
}

Fraction Fraction::sum(const Fraction& b) const{
    Fraction res;

    if(denominator_ == b.denominator_){
        res.denominator_ = denominator_;
        res.numerator_ = numerator_ + b.numerator_;
    }
    else{
        res.denominator_ = denominator_ * b.denominator_;
        res.numerator_ = numerator_ * b.denominator_ + b.numerator_ * denominator_;
    }

    res.normalise();

    return res;
}

Fraction Fraction::sub(const Fraction& b) const{
    Fraction res;

    if(denominator_ == b.denominator_){
        res.denominator_ = denominator_;
        res.numerator_ = numerator_ - b.numerator_;
    }
    else{
        res.denominator_ = denominator_ * b.denominator_;
        res.numerator_ = numerator_ * b.denominator_ - b.numerator_ * denominator_;
    }

    res.normalise();

    return res;
}

Fraction Fraction::mul(const Fraction& b) const{
    Fraction res;

    res.numerator_ = numerator_ * b.numerator_;
    res.denominator_ = denominator_ * b.denominator_;

    res.normalise();

    return res;
}

Fraction Fraction::div(const Fraction& b) const{
    Fraction res = b;
    int t;

    t = res.denominator_;
    res.denominator_ = res.numerator_;
    res.numerator_ = t;

    res.numerator_ = numerator_ * res.numerator_;
    res.denominator_ = denominator_ * res.denominator_;

    res.normalise();

    return res;

}

int main(){
    Fraction().div({2, 4}).write(); cout << ' ';
  Fraction(1,1).div({2, 4}).write(); cout << ' ';
  Fraction(2,4).div({3, 9}).write(); cout << ' ';
  Fraction(-2,4).div({1, 2}).write(); cout << ' ';
  Fraction(3,27).div({-27, 81}).write(); cout << '\n';
    

    return 0;
}