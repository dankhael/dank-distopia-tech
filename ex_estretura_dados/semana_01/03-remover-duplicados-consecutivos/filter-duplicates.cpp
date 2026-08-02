#include <iostream>
#include "print_array.h"

using namespace std;

int filter_duplicates(const int a[], int n, int b[]){

    int j, l= 0;
    bool flag = false;

    for (int i = 0; i < n; i++){
        if (flag){
            if (j != a[i]){
                b[l] = a[i];
                j = a[i];
                l++;
            }
        }
        else{
            flag = true;
            j = a[i];
            b[l] = j;
            l++;
        }
        
    }
    return l;



}


int main(){

    const int n = 11;
  const int a[n] = { 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 33 };
  int b[n] = { 0 };
  int nf = filter_duplicates(a, n, b);
  print_array(b, nf);


    return 0;
}