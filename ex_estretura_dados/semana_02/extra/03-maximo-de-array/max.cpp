#include <iostream>
using namespace std;

int max(const int a[], int n){

    int res = a[0];
    int test;    

    for (int i = 1; i<= n-1;i++){
        test = a[i];

        if (res < test){
            res = test;
        }
    }

    return res;

}


int main(){
    const int n = 3; 
  const int a[n] = { -3, -2, -1 };
  cout << max(a, n) << '\n';
  return 0;
}