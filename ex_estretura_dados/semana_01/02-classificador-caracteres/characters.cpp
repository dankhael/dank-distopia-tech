#include <iostream>
using namespace std;

int main(){
    char t;

    cin >> t;

    if (t >= 48 && t <= 57){
        cout << "DIGIT";
    }

    else if ((t >= 65 && t <= 90) || (t >= 97 && t <= 122)){
        cout << "LETTER";
    }

    else{
        cout << "OTHER";
    }
    return 0; 
}