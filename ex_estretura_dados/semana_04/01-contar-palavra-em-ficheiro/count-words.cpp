#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int count(const string& fname, const string& word){
    string y;
    int res = 0;
    string nw = word;
    
    for(char& x: nw) {x = toupper(x);}

    ifstream in(fname);
    

    while (in >> y){

        for(char& x: y) {x = toupper(x);}

        if (y == nw){
            res += 1;
        }

    }

    return res;

}

int main(){
    cout << count("p1_test_a.txt", "THE") << '\n';

    return 0;
}