#include <iostream>
#include "Color.h"

using namespace std;

Color::Color (unsigned char r, unsigned char g, unsigned char b){
    this->r = r;
    this->g  = g;
    this->b = b;
}

Color::Color (const Color& c){
    r = c.r;
    g = c.g;
    b = c.b;
}

unsigned char Color::red() const{
   return this->r; 
}

unsigned char Color::green() const{
    return this->g;
}

unsigned char Color::blue() const{
    return this->b;
}

bool Color::equal_to(const Color& other) const{
    if(r == other.r && g == other.g && b == other.b){
        return true;
    }
    return false;
}

const Color Color::RED (255,0,0);
const Color Color::GREEN (0,255,0);
const Color Color::BLUE(0,0,255);
const Color Color::WHITE (255,255,255);
const Color Color::BLACK (0,0,0);

void Color::invert(){
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
}
/*int main(){
    Color c (1, 2, 3);
  const Color& r = c;
  cout << (int) r.red() << ' '  
       << (int) r.green() << ' '  
       << (int) r.blue() << ' '
       << boolalpha << r.equal_to(r) << '\n';

    return 0;
}*/
