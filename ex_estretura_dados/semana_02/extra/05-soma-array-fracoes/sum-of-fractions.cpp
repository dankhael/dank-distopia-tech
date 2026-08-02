#include <iostream>
#include "fraction.h"

using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }

    return gcd(b, a % b);
}

fraction sum(const fraction fa[], int n){
    
    fraction f_1 = fa[0];
    fraction f_2;


    for (int i = 1; i < n; i++){
        f_2 = fa[i];
        
        if (f_1.den != f_2.den){
            f_1.num = f_1.num * f_2.den;
            f_2.num = f_2.num * f_1.den;
            f_1.den = f_1.den * f_2.den;
            
        }

        f_1.num = f_1.num + f_2.num;
    }


    int div;
   
    div = gcd(f_1.num,f_1.den);

    f_1.num = f_1.num / div;
    f_1.den = f_1.den / div;

    if (f_1.den < 0){
        f_1.num = f_1.num * (-1);
        f_1.den = f_1.den * (-1);
    }

    return f_1;


}

int main(){
    const int n = 5;
  const fraction fa[n] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
  cout << sum(fa, n) << '\n';
  return 0;
}
