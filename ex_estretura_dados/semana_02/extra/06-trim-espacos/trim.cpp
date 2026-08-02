#include <iostream>
using namespace std;

 void trim(char s[]){
    int i = 0,j = 0;
    int flag = -1;

    while(s[i] == ' ' && s[i] != '\0'){ 
        i++;
    }

    if (i != 0){
    while (s[i] != '\0'){
        s[j] = s[i];
        s[i] = ' ';

        j++;
        i++;
    }

    i = 0;
    }
    
    while (s[i] != '\0'){
        if (s[i] == ' ' && flag == -1){
            flag = i;
        }
        else if (s[i] == ' '){
            
        }

        else{
            flag = -1;
        }
        i++;
    }


    if (flag != -1){
        s[flag] = '\0';
    }
    
 }


 int main(){
    char s[] = "    abc def";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
    return 0;
 }