#include <iostream>
using namespace std;

const char* longest(const char* pa[]){
    int i = 0;
    int j = 0;

    int t_1 = 0;
    int t_2 = 0;

    int k_1;
    int k_2;
    
    bool flag = false;

    while (pa[i] != nullptr){
        if (flag){
            k_2 = i;
        }
        else{
            k_1 = i;
        }

        j = 0;

        while (pa[i][j] != '\0'){

            if (flag != true){
                t_1 += 1;
            }
            else{
                t_2 += 1;
            }
            j++;   
        }

        if ((t_2 > t_1 || t_2 == t_1) && flag){
            t_1 = t_2;
            k_1 = k_2;
        }
        flag = true;
        i++;
        t_2 = 0;
    }

    return pa[k_1];

}


int main(){

    const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
    cout << "\"" << longest(pa) << "\"\n";

    return 0;
}