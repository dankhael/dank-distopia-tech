#include <iostream>
#include "Polygon.h"
#include "Point.h"
#include <vector>

using namespace std;
Polygon::Polygon(vector <Point> x){
    int t = x.size();
    for (int i = 0; i < t; i++){
        pontos.push_back(x[i]);
    }
}

void Polygon::show() const{
    int t = pontos.size();
    cout << '{';

    for (int i = 0; i < t; i++){
        pontos[i].show();
    }

    cout << '}';
}