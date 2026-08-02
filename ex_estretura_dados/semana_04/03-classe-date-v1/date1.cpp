#include <iostream>
#include <iomanip>
#include "Date1.h"

using namespace std;

Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}
Date::Date(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

int Date::get_day() const{
    return day;
}

int Date::get_month() const{
    return month;
}

int Date::get_year() const{
    return year;
}


bool is_befo(const Date& date1, const Date& date2){

    if(date1.get_year() < date2.get_year()){
        return true;
    }
    else if(date1.get_year() == date1.get_year()){
        if (date1.get_month() < date2.get_month()){
            return true;
        }
        else if(date1.get_month() == date2.get_month()){
            if(date1.get_day() < date2.get_day()){
                return true;
            }
        }
    }
    return false;
}

int main(){
    Date d6(2022,5,29), d7(2022, 5, 28);
    d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';
    
    return 0;
}