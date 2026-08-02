#include <iostream>
#include <string>

using namespace std;
bool pangram(const string& s, string& m){
    
    char alfabeto [27] = "abcdefghijklmnopqrstuvwxyz";
    bool pertece [26] = {false};

    bool res = true;

    int i = 0, j = 0;
    int t;

    while(s[i] != '\0'){
        if (s[i] >= 65 && s[i] <= 90){
            t = s[i] - 65;
            pertece[t] = true; 
        }
        else if (s[i] >= 97 && s[i] <= 122){
            t = s[i] - 97;
            pertece[t] = true;
        }
        i++;
    }

    for (int i = 0; i < 26; i++){
        if (pertece[i] != true){
            m.push_back(alfabeto[i]);
            res = false;
            j++;
        }
    }
    m[j] = '\0';

    return res;
}


int main(){
    string s = "A quick brown fox jumps over a classy dog";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " << boolalpha << r << " \"" << m << "\"\n";


    return 0;
}