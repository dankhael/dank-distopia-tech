
#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(){
    x_ = 0;
    y_ = 0;
}

Point::Point(int a, int b){
    x_ = a;
    y_ = b;
}

Point::Point(const Point& p){
    x_ = p.get_x();
    y_ = p.get_y();
}

int Point::get_x() const{
    return x_;
}

int Point::get_y() const{
    return y_;
}

Point& Point::operator=(const Point& p){
    x_ = p.get_x();
    y_ = p.get_y();

    return *this;
}

Point Point::operator+(const Point& p) const{
    
    return Point(x_ + p.get_x(), y_ + p.get_y());
}

Point& Point::operator+=(const Point& p){
    x_ += p.get_x();
    y_ += p.get_y();

    return *this;
}

Point Point::operator*(int v) const{
    
    return Point(x_ * v, y_ * v);
}
Point operator*(int x, const Point& p) {
  return Point(x * p.get_x(), x * p.get_y());
}

ostream& operator<<(ostream& os, const Point& p) {
  os << "(" << p.get_x() << "," << p.get_y() << ")";
  return os;
}


int main(){
   Point a(1,2), b(3,4), c = a * 2, d(5,6);
  b = 2 * d;
  cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; 

    return 0;
}