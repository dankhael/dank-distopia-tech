#include <iostream>
#include <string>
#include "print_vector.h"

using namespace std;

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){
    int i = 0;

    for(T x: v){
        if (x > max){
            v.at(i) = max;
        }
        else if (x < min){
            v.at(i) = min;
        }

        i++;
    } 

}

int main(){
    vector<string> v { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" };
  normalise(v, string("Antonio"), string("Zacarias")); print(v);


    return 0;
}