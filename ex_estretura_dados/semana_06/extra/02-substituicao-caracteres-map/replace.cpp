#include <iostream>
#include <string>
#include <map>

using namespace std;

void replace(const map<char, char>& r, string& s){
    map<char, char>::const_iterator it;
    int i = 0;

    for (char c : s){
        it = r.find(c);

        if (it != r.end()){
            s[i] = it -> second;
        }
        i++;
    }

}

int main(){
    string s = "C / C++ @ LEIC";
    replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
    cout << s << '\n';


    return 0;
}