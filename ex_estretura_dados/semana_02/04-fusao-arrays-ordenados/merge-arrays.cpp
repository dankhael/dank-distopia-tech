#include <iostream>
#include "print_array.h"

using namespace std;

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]){
    
    int total = na +nb;
    int ta = 0;
    int tb = 0;

    for (int i = 0; i < total;i++){
        if (ta >= na){
            c[i] = b[tb];
            tb++;
            break;
        }
        if (tb >= nb){
            c[i] = a[ta];
            ta++;
            break;
        }

        if (a[ta] <= b[tb]){
            c[i] = a[ta];
            ta++;
        }
        else{
            c[i] = b[tb];
            tb ++;
        }



    }
    
}

int main(){
    const int NA = 2, NB = 3;
    int a[NA] = { 0, 1 };
    int b[NB] = { 2, 3, 4 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB); 
    return 0;
}

