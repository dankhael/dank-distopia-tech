#include <iostream>
using namespace std;

bool prime(int n){
    if (n == 1 || n == 0){
        return false;
    }
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void per (int n){
     int i = 1;
    int t = n;
    int res = 0;

    while (n >= i){
        i *= 2;
    }

    i = i / 2;

    while (t != 0){
        if (t - i >= 0){
            t = t - i;
            res ++;
        }
        i = i / 2;
    }
    if(prime(n) && prime(res)){
        cout << n << ' ';
    }


}


int main(){
    int start;
    int end;

    cin >> start;
    cin >> end;

    for (int i = start; i <= end; i++){
        per(i);
    }

    return 0;
}