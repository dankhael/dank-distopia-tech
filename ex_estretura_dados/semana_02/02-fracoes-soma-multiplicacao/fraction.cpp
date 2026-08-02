#include <iostream>
#include "fraction.h"

using namespace std;

int gcd(int a ,int b){
    
    if (b == 0){
        return a;
    }

    return gcd(b, a%b);
}


fraction add(fraction a, fraction b){
    
    fraction res;
    int div;

    if (a.den !=  b.den){
        a.num = a.num * b.den;
        b.num = b.num * a.den;

        a.den = a.den * b.den;
        b.den = a.den;
    }

    res.num = a.num + b.num;
    res.den = a.den;

    div = gcd(res.num, res.den);
    
    res.num = res.num / div;
    res.den = res.den / div;

    if (res.den < 0){

        res.num = res.num * (-1);
        res.den = res.den * (-1);

    }


    return res;

}

fraction mul(fraction a, fraction b){

    fraction res;
    int div;

    res.num = a.num * b.num;
    res.den = a.den * b.den;

    div = gcd(res.num, res.den);
    
    res.num = res.num / div;
    res.den = res.den / div;

    if (res.den < 0){

        res.num = res.num * (-1);
        res.den = res.den * (-1);

    }
        

    return res;
}



int main(){

    fraction a { -3, 2 }, b { -2, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; 

    return 0;
}