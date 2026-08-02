#include <iostream>
using namespace std;

void rle_encode(const char str[], char rle[]){
    int i = 0;
    int j = 0;
    char t;
    int n[2];
    n[1] = 48;
    n[0] = 48;

    
    while (str[i] != '\0'){
        if(n[0] == 48 && n[1] == 48){
            n[0]++;
            t = str[i];
        }
        else if(t == str[i]){
            if (n[0] == 57){
                n[1] ++;
                n[0] = 48; 
            }
            else{
                n[0] ++;
            }
            
        }
        else{
            if (n[1] != 48){
                rle[j] = n[1];
                j++;
            }

            rle[j] = n[0];
            j++;

            rle[j] = t;
            j++;

            t = str[i];
            n[0] = 49;
            n[1] = 48;
        }

        i++;
    }
    i = 0;

    if (str[i] != '\0'){
        if (n[1] != 48){
                rle[j] = n[1];
                j++;
            }

            rle[j] = n[0];
            j++;

            rle[j] = t;
            j++;

            t = str[i];
            n[0] = 49;
            n[1] = 48;
            rle[j] = '\0';
    }
    else{
        rle[0] = '\0';
    }
     

}


int main(){
    char rle[2 + 1] = { -1, -1, -1 }; 
  rle_encode("a", rle);
  cout << rle << endl;

  return 0;
}