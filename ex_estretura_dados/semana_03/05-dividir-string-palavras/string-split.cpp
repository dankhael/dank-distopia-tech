#include <iostream>
#include "print_string.h"
#include <string>
using namespace std;

void split(const string& s, vector<string>& v){
    int i = 0;
    int len = 0, pos;
    string res;

    while (s[i] != '\0'){
        if(s.find(' ', i) == string::npos){
            len = s.length() - i;
            res = s.substr(i, len);
            v.push_back(res);
            break;

        }
        else{
        pos = s.find("  ", i);

        len = pos - i;
        if (len == 0){
            i++;
            continue;
        }
        else{
            res = s.substr(i,len);
            v.push_back(res);
            i = pos + 1;
        }



        }
    }
}

int main(){
  string s = "C++ LEIC  FCUP FEUP";
  vector<string> v;
  split(s, v);
  print(v);

  return 0;
}