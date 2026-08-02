#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

class Polygon{
    public:
        Polygon(vector <Point>);
        void show() const;

    private:
        vector <Point> pontos;
};


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

#endif