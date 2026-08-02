#include <iostream>
#include "Operation.h"
#include <cmath>

using namespace std;

class Sum : public Operation{
    public:
        Sum(int a, int b);

        int operation() const;
};

Sum::Sum(int a, int b):Operation(a, b){}  

int Sum::operation() const{
    return get_op1() + get_op2();
}

class Power : public Operation{
    public:
        Power(int a, int b);

        int operation() const override;
};

Power::Power(int a, int b):Operation(a, b){}

int Power::operation() const{
    return pow(get_op1(), get_op2());
}


int main(){
    const Operation& s = Sum(2, 10); cout << s.operation() << ' '; 
    const Operation& p = Power(2, 10); cout << p.operation() << endl;

    return 0;
}