#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longest_prefix(const vector<string>& v){
    string res = v.at(0);
    int t = 0;
    string auxiliar = "";
    
    for (int i = 1; i < v.size(); i++){
        if(res.length() > v.at(i).length()){
            t = v.at(i).length();
        }
        else{
            t = res.length();
        }

        for (int j = 0; j < t; j++){
            if (res.at(j) != v.at(i).at(j)){
                res = auxiliar;
                auxiliar = "";
                break;
            }
            auxiliar.push_back(res.at(j));
        }
    }
        return res;
}

int main(){

    
cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";

    return 0;
}