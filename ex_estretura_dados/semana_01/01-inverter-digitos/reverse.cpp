#include <iostream>
using namespace std;

int main(){
    int t, digit, res = 0;
    cin >> t;
    while (t != 0) {
        digit = t % 10;
        t /= 10;
        res = res * 10 + digit;
    }
    cout << res;

    return 0;
}