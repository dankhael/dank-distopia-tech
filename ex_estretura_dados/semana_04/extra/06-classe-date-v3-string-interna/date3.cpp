#include <iostream>
#include "Date3.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

Date::Date(){
    yyyymmdd = "00010101";
}

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

Date::Date(int year, int month, int day){
    yyyymmdd = "00000000";

    if(valid_year(year)){
        if(valid_month(month)){
            if(valid_day(day,month,year)){
                if (year < 10){
                    yyyymmdd = "000" + to_string(year);
                }
                else if(year < 100){
                    yyyymmdd = "00" + to_string(year);
                }
                else if (year < 1000){
                    yyyymmdd = '0' + to_string(year);
                }
                else{
                    yyyymmdd = to_string(year);
                }

                if(month < 10){
                    yyyymmdd += '0' + to_string(month);
                }
                else{
                    yyyymmdd += to_string(month);
                }

                if (day < 10){
                    yyyymmdd += '0' + to_string(day);
                }
                else{
                    yyyymmdd += to_string(day);
                }   
            }
        }
    }
}

Date::Date(const string& year_month_day){
    istringstream iss(year_month_day);
    yyyymmdd = "00000000";

    int d,m,y;
    char sep_1, sep_2;

    if(iss >> y >> sep_1 >> m >> sep_2 >> d){
        if(sep_1 == '/' && sep_2 == '/'){
            if(valid_year(y)){
            if(valid_month(m)){
            if(valid_day(d,m,y)){
                if (y < 10){
                    yyyymmdd = "000" + to_string(y);
                }
                else if(y < 100){
                    yyyymmdd = "00" + to_string(y);
                }
                else if (y < 1000){
                    yyyymmdd = '0' + to_string(y);
                }
                else{
                    yyyymmdd = to_string(y);
                }

                if(m < 10){
                    yyyymmdd += '0' + to_string(m);
                }
                else{
                    yyyymmdd += to_string(m);
                }

                if (d < 10){
                    yyyymmdd += '0' + to_string(d);
                }
                else{
                    yyyymmdd += to_string(d);
                }   
            }
        }
    }
    }
    }
}


bool Date::is_valid() const{
    if(yyyymmdd.substr(0, 4) == "0000" || yyyymmdd.substr(4, 2) == "00" || yyyymmdd.substr(6, 4) == "00"){
        return false;
    }
    return true;
}

int main(){
    Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;

    return 0;
}