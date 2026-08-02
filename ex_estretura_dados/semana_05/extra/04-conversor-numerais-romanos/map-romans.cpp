#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned roman_to_arab(const string& roman){

    vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};


    unsigned int t = roman.length();
    unsigned int k = roman_to_int.size();

    unsigned int i = 0;
    unsigned int res = 0;
    unsigned int m;

    bool flag = false;
    

    while (i < t){    
        for (unsigned int j = 0; j <k; j++){

            if ((roman[i] == roman_to_int[j].first)){
                if(flag){
                    if (roman_to_int[j].second > m){
                        
                        res += roman_to_int[j].second - m;
                        flag = false; 
                    }

                    else{
                        res +=  m;
                        m = roman_to_int[j].second;
                    }
                }
                else{
                    m = roman_to_int[j].second; 
                    flag = true;  
                }
            }  
        }

        i++;
    }


    if (flag){
        res += m;
    }
    
    return res;
}


int main(){

    string r = "MMMDCCCLXXXVIII";
    cout << roman_to_arab(r) << '\n';


    return 0;
}