#include "Shape.h"
#include <iostream>
#include <cmath>

using namespace std;



class Circle : public Shape{
    public:
        Circle (const point& center, double radius);

        virtual double area() const override;
        virtual double perimeter() const override;

        bool contains(const point& p) const override;
     
    private:
        double radius_;
};

Circle::Circle(const point& center, double radius):Shape(center){
    radius_ = radius;
}

double Circle::area() const{
    double res;
    res = radius_ * radius_ * M_PI;

    return res;
}

double Circle::perimeter() const{
    double res;
    res = radius_ * 2 * M_PI;

    return res;
}

bool Circle::contains(const point& p) const{
    double distance;

    distance = (p.x - get_center().x) * (p.x - get_center().x) +  (p.y - get_center().y) * (p.y - get_center().y);
    distance = sqrt(distance);

    if (distance <= radius_){
        return true;
    }

    return false;
}

class Rectangle : public Shape{
    public:
        Rectangle(const point& center, double width, double height);

        virtual double area() const override;
        virtual double perimeter() const override;

        bool contains(const point& p) const override;

    private:
        double width_;
        double height_;
};

Rectangle::Rectangle(const point& center, double width, double height):Shape(center){
    width_ = width;
    height_ = height;
}

double Rectangle::area() const{
    return width_ * height_;
}

double Rectangle::perimeter() const{
    return width_ * 2 + height_ * 2;
}

bool Rectangle::contains(const point& p) const{
    if ((p.x >= (get_center().x - width_ / 2)) && (p.x <= (get_center().x + width_ / 2))){
        if ((p.y >= (get_center().y - height_ / 2)) && (p.y <= (get_center().y + height_ / 2))){
            return true;
        }
    }
    return false;   
}

int main(){
    Circle c({1, 2}, 3);
  point a [] { 
      { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0 }, { 3.9,  2.0 }, 
      {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1 }, { 1.0, -1.1 }, 
      {  1.2, -0.3 }, {  5.2,  5.1 }, { 2.1, -0.5 }, { 3.2,  5.5 } };
  cout << fixed << setprecision(2);
  for (point& p : a)  
    if (c.contains(p))
      cout << '(' << p.x << ',' << p.y << ')';
  cout << '\n';


   
    return 0;
}