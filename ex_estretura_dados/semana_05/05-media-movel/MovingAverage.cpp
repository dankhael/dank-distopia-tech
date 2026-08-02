#include <list>
#include <iostream>
#include "MovingAverage.h"
#include <iomanip>

using namespace std;

MovingAverage::MovingAverage(size_t n){
    n_ = n;
} 

void MovingAverage::update(double value){
    if(n_ == values_.size()){
        values_.pop_front();
        values_.push_back(value);

    }
    else{
        values_.push_back(value);
    }
}


double MovingAverage::get() const{
    double res = 0.0;
    
    for (auto it = values_.begin(); it != values_.end(); ++it) {
        res += *it;
    }
    

    res = res / values_.size();

    return res;

}




int main(){
   MovingAverage ma(1); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n';



    return 0;
}