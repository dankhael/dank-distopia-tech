#include "Date.h"

Date::Date(){
    year_ = 1;
    month_ = 1;
    day_ = 1;
}

Date::Date(int y, int m, int d){
    year_ = y;
    month_ = m;
    day_ = d;
}

bool Date::is_before(const Date& date) const{
    if(year_ < date.year_){
        return true;
    }
    else if(year_ == date.year_){
        if (month_ < date.month_){
            return true;
        }
        else if(month_ == date.month_){
            if(day_ < date.day_){
                return true;
            }
        }
    }
    return false;
}
