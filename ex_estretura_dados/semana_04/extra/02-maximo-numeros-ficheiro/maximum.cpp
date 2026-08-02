#include <iostream>
#include "show_file.h"
#include <iomanip>
#include <fstream>
#include <sstream>


void maximum(const string& input_fname, const string& output_fname){
    string line;
    double y;
    double num_1;
    int size = 0;
    bool flag = false;


    ifstream in(input_fname);
    ofstream out(output_fname);


    while(getline(in, line)){
        istringstream iss(line);
        
        while (iss >> y){
            if (flag == false){
                num_1 = y;
                flag = true;
            }
            else if(flag){
                if (y > num_1){
                    num_1 = y;
                }
            }
            out <<fixed<<setprecision(3) << y << "\n";
            size++; 
        }
        
        

    }
    out <<"count=" << size << "/max=" << num_1;
}

int main(){
  maximum("p4_test1.txt", "p4_test1_out.txt");
  show_file("p4_test1_out.txt");

  return 0;
}
