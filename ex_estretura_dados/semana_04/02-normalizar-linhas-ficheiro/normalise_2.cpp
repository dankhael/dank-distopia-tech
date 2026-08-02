#include <iostream>
#include "print.h"
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

void normalise(const string& input_fname, const string& output_fname){
string a[10] = {" "};
int i = 0;
int fim = -1;
int len;

ifstream in(input_fname);
ifstream in_2(input_fname);
ofstream out(output_fname);

string line;
bool flag = false;
string res = "";
string y;

while(getline(in,line)){

if (line != ""){
    

        for (char& x: line){

            if (flag == false && x != ' '){
                flag = true;
               
            }
            if (flag){
                
                if (x >= 97 && x <= 122){
                    x = toupper(x);
                    res.push_back(x);
                    fim = -1;
                    i++; 
                }
                else{
                    if (x == ' ' && fim == -1){
                    fim = i;
                    
                    }
                    res.push_back(x);
                    i++; 
              
                }
            }
        }

        if (fim != -1){
           len = res.length();

           for(int j = fim; j < len; j++){
                res[j] = '\0';
           }
        }
        
        out << res;
        res = "";
        
        i = 0;
        fim = -1;
        flag = false;
        out << "\n";
    }    
  
}

}






int main(){

normalise("p3_test4.txt", "p3_test4_out.txt"); 
  print("p3_test4_out.txt");


return 0;

}