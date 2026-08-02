#include "Figure.h"
#include <vector>
#include <iostream>

using namespace std;

class Rectangle : public Figure{
    public:
        Rectangle (int x_center, int y_center, int width, int height);

        void draw() const override                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ;

    private:
        int width_;
        int height_;
};

Rectangle::Rectangle(int x_center, int y_center, int width, int height):Figure(x_center, y_center){
    width_ = width;
    height_ = height;
}

void Rectangle::draw() const{
    cout << "R(" << x_center_ << "," << y_center_ << ")(" << width_ << "," << height_ << ")";
}

class Circle : public Figure{
    public:
        Circle(int x_center, int y_center, int radius);

        void draw() const override;

    private:
        int radius_;
};

Circle::Circle(int x_center, int y_center, int radius): Figure(x_center, y_center){
    radius_ = radius;
}

void Circle::draw() const{
    cout << "C(" << x_center_ << "," << y_center_ << ")(" << radius_ <<  ")";
}


int main(){
   vector<Figure*> figures = {
    new Rectangle(10,10,200,100),
    new Circle(20,20,500),
    new Rectangle(-10,-20,150,250),
    new Circle(0,0,100) };
  for (const auto& f : figures) f->draw(); 
  cout << endl; for (const auto& f : figures) delete f;


    return 0;
}