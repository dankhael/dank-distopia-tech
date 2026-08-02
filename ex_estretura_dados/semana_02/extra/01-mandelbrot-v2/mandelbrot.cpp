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

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    complex t = {0,0};

    if (n == 0){
        z_n.x = 0;
        z_n.y = 0;
    }
    else{
        for (unsigned int i = 1; i<= n;i++){
        mul(t, t, z_n);
        t = z_n;
        
        add(t,c,z_n);
        t = z_n; 
        

    }
    }
    

}

int main (){

    complex z_n;
    mandelbrot({-1.2, 0.4}, 7, z_n);
    cout << z_n << '\n';

    return 0;
}