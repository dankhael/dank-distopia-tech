#include <iostream>
#include "Color.h"


int main(){
    Color c (1, 2, 3);
    const Color& r = c;

    cout << r.red() << ' ' << r.blue() << ' ' << r.green() << "\n";

    return 0;


}