#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int j;
    int pr;
    double res = 0;

    cin >> j;
    cin >> pr;
    
    for (int i = 0; i <= j; i++){
        res += pow(-1, i) / (2 * i + 1);
    }

    res *= 4;

    cout <<fixed << setprecision(pr) << res;
    return 0;

}