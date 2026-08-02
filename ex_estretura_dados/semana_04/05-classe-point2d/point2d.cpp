#include <iostream>
#include <iomanip>
#include "Point2d.h"
#include <math.h>

using namespace std;

void Point2d::translate(const Point2d& t){
    x = x + t.x;
    y = y + t.y;
    
}

double Point2d::distance_to(const Point2d& p) const{
    double res;
    double t_1, t_2;

    t_1 = x - p.x;
    t_2 = y - p.y;

    t_1 =  pow(t_1, 2);
    t_2 = pow(t_2, 2);

    res = t_1 + t_2;
    res = sqrt(res);
    
    return res;
}


int main(){
   Point2d a { 1.0, 2.1 }, b { 2.0, 3.1 };
  cout << fixed << setprecision(2) 
       << a.distance_to(b) << '\n'; 


       return 0;
}