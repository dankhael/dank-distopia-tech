#include <vector>
#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"

using namespace std;


void born_before(const vector<Person>& persons, const Date& date){
    //cout << persons.size() << "\n";
    bool t;
    bool flag = true;
    if (flag){
                date.show();
                cout << ": ";
                flag = false;
            }

    int y = persons.size();

    for (int i = 0; i < y;i++){
        t = persons[i].get_birth_date().is_before(date);

        if (t){
            
            persons[i].show();
            cout << ' ';
        }
    }

}


int main(){
    
  //  born_before({ },{2000,1,1}); 
   born_before({{"Rui",{2000,4,5}}, {"Ana",{1999,5,11}}, {"Susana",{1999,5,13}},{"Pedro",{2010,2,10}}},{2020,1,1});



    return 0;
}