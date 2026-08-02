#include <iostream>
#include "complex.h"
using namespace std;

complex sum (complex a, complex b){
    complex c;

    c.real = a.real + b.real;
    c.img = a.img + b.img;

    return c;
}

complex mul (complex a, complex b){
    complex c;

    c.real = (a.real*b.real - a.img*b.img);
    c.img = (a.real*b.img + b.real*a.img);

    return c;  
}

void mandel(complex c, int n, complex z[]){
    
    complex t;

    for (int i = 0; i < n; i++){
        if (i == 0){
            z[i].real = 0;
            z[i].img = 0;
        }
        else{
            t = mul(z[i-1], z[i-1]);
            t = sum(t, c);

            z[i] = t;
        }

    }
    
 

}



int main(){

    complex c = { 0, 0 };
    const int n = 1;
    complex z[n];
    mandel(c, n, z);
    print(z, n);

    return 0;
}
