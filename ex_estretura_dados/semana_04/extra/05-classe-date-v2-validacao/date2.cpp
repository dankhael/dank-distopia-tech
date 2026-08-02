#include <iostream>
#include "Date2.h"
#include <string>
#include <sstream>


using namespace std;

bool leap(int y){
    if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)){
        return true;
    }
    return false;
}

bool valid_month(int x){

    if (x >= 1 && x <= 12){
        return 1;
    }
    return 0;
}

bool valid_year(int x){
    
    if(x >= 1 && x <= 9999){
        return 1;
    }
    return 0;
}

bool valid_day(int x, int y, int z){
    if(y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12){
        if (x >= 1 && x <= 31){
            return 1;
        }
        return 0;
    }
    if(y == 2){
        if(leap(z)){
            if (x >= 1 && x <= 29){
                return 1;
            }
            return 0;
        }
        else{
            if(x >= 1 && x <= 28){
                return 1;
            }
            return 0;
        }
    }
    else{
        if(x >= 1 && x <= 30){
            return 1;
        }
    }
    return 0;
}

Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int y, int m, int d){
    year = 0;
    month = 0;
    day = 0;

    if(valid_year(y)){
        if(valid_month(m)){
            if(valid_day(d,m,y)){
                year = y;
                month = m;
                day = d;
            }
        }
    }
}

Date::Date(const string& year_month_day){
    istringstream iss(year_month_day);

    int d,m,y;
    char sep_1, sep_2;

    year = 0;
    month = 0;
    day = 0;

    if(iss >> y >> sep_1 >> m >> sep_2 >> d){
        if(sep_1 == '/' && sep_2 == '/'){
            if(valid_year(y)){
                if(valid_month(m)){
                    if(valid_day(d,m,y)){
                        year = y;
                        month = m;
                        day = d;
                    }
                }
            }
        }
    }
}

bool Date::is_valid() const{
    if(year == 0 || month == 0 || day == 0){
        return false;
    }
    return true;
}


int main(){
    Date d2(2022, 4, 31);
    d2.write();
    cout << (d2.is_valid() ? "" : "-invalid") << endl;


    return 0;
}

