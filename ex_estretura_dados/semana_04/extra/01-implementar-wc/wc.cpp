#include <iostream>
#include "wc.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

wcresult wc(const string& filename){
    
    wcresult res;
    string y;

    res.lines = 0;
    res.words = 0;
    res.bytes = 0;

    ifstream in(filename);
    string line;

    while (getline(in,line)){
    
    res.lines += 1;
    istringstream iss(line);
    res.bytes += line.length() + 1; 

    while(iss >> y){
        res.words += 1;
    }
    }

return res;

}

int main(){
  wcresult r = wc("p2_test2.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';

  return 0;
}