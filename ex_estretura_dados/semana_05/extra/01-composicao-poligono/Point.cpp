#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

void Point::show() const{
    cout << '(' << x << "," << y << ")";
}

