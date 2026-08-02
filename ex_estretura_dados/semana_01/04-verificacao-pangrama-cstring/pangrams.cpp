#include <iostream>
using namespace std;

bool pangram(const char s[], char m[]){
    bool ar[26];
    char alfabeto[27] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int a = 97;
    int z = 122;
    int m_a = 65;
    int m_z = 90;
    int l = 0;
    bool res = true;


    while(s[i] != '\0'){
        if (s[i] >= a && s[i] <= z){
            ar[s[i] - a] = true; 
        }

        else if (s[i] >= m_a && s[i] <= m_z){
            ar[s[i] - m_a] = true;
        }

        i++;
    }

    for (int i = 0; i < 26; i++){
        if (ar[i] == false){
            m[l] = alfabeto[i];
            l ++;
            res = false;
        }
    }

    if (res){
        m[0] = '\0';
    }

    return res;
    
}


int main(){

    char s[] = "A quick brown fox jumps over a classy dog";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
       << boolalpha << r << " \"" << m << "\"\n";
       return 0;

}