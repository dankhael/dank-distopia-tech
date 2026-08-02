#include <iostream>
#include "show_file.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>

void calc_medians(const string& input_fname, const string& output_fname){
    string line;
    string x;
    double y;
    double mediana[10];
    int i = 0;

    ifstream in(input_fname);
    ofstream out(output_fname);

    while(getline(in,line)){
        istringstream iss(line);
        iss >> x;

        if(x[0] != '#'){
            out << x << " ";
            while(iss >> y){
                //out <<fixed << setprecision(1)<< y << " ";
                mediana[i] = y;
                i++;
                
            }

        sort(mediana ,mediana + i);

        if (i % 2 == 0){
            
            y = (mediana[i/2-1] + mediana[i/2]) / 2.0;
            out << fixed << setprecision(1) << y;
        }
        else{
    
            y = mediana[i/2];
            out <<fixed << setprecision(1) << y;
        }
        i = 0;
        out << "\n";
        }
        
    }


}

int main(){
    calc_medians("p5_test3.txt", "p5_test3_out.txt");
    show_file("p5_test3_out.txt");

    return 0;
}


