#include <iostream>
#include "complex.h"
#include <cmath>

using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}


void mul(const complex& a, const complex& b, complex& r){
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + b.x * a.y; 

}

double norm(const complex& c){
    double res,a,b;

    a = c.x * c.x;
    b = c.y * c.y;

    res = a + b;
    res = sqrt(res);

    return res;

}

int main (){

  complex a { 0, 1 }, b { 2, 1}, s, m;

  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
    return 0;
}