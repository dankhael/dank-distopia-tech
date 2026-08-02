#include <iostream>
#include "print.h"
#include <fstream>
#include <string>
using namespace std;

void upperca(string& word){
    for (char& d : word)
        d = toupper(d);
}

void normalise(const string& input_fname, const string& output_fname){
    
    ofstream out(output_fname);
    ifstream in(input_fname);

    string lin;

    while(getline(in, lin)){

        lin.erase(0, lin.find_first_not_of(' '));
        lin.erase(lin.find_last_not_of(' ') + 1);
        
        upperca(lin);

        if (!lin.empty())
            out << lin << endl;
    }
}