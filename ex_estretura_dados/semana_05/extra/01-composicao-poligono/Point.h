#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);

    void show() const;
    
};
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



#endif
int main(){
   Point p1, p2(0, 1); 
  p1.show(); p2.show(); cout << '\n';

  return 0;
}