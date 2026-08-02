#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longest_prefix(const vector<string>& v){
    string res = v.at(0);
    int t = 0;
    string auxiliar = "";
    
    for (string x: v){
        if(res.length() >= x.length()){
            t = x.length();
        }
        else{
            t = res.length();
        }

        for (int j = 0; j < t; j++){
            if (res.at(j) != x.at(j)){
                res = auxiliar;
                auxiliar = "";
                break;
            }
            auxiliar.push_back(res.at(j));
        }
        auxiliar = "";
    }
        return res;
}

int main(){

    
cout << "\"" << longest_prefix({ "a", "b", "a" }) << "\"\n";

    return 0;
}