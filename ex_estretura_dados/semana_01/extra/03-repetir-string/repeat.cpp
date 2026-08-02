#include <iostream>
using namespace std;

char* repeat(const char str[], int n){
    int i = 0;
    int t = 0;
    int m = 0;

    while (str[i] != '\0'){
        i ++;
    }

    t = i * n + 1;
    char* c = new char [t];
    t = i;

    for (int i = 0; i < n; i++){
        if (i == n-1){
            for (int j = 0; j <= t; j++){
            c[m] = str[j];
            m++;
        }  
        }
        else{
            for (int j = 0; j < t; j++){
            c[m] = str[j];
            m++;
        }
        }
        
    }

    return c;  

}

int main(){
    const char str[] = "H e l l o";
    char* r = repeat(str, 2);
    cout << "\"" << r << "\"\n";
    delete [] r;

    return 0;
}