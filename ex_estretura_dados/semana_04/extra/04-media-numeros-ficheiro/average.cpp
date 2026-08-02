#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

double average(const string& fname){
    double x,sum = 0;
    int i = 0;

    ifstream in(fname);
    string line;

    while (getline(in,line)){
        istringstream iss(line);

        while(true){
            if (iss.eof()) break;
            if (iss >> x){
                sum += x;
                i++;
            }
            iss.clear();
            iss.ignore(1);  

        }

    }
    return sum/i;

}


int main(){

double m = average("p6_test4.txt"); 
  cout << fixed << setprecision(2) << m << '\n';

  return 0;
}