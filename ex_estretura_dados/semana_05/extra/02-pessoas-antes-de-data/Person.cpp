
#include <string>
#include "Person.h"
#include "Date.h"

Person::Person(){
    name_ = "NO_NAME";
    Date k;
    birth_date_ = k;
}

Person::Person(const std::string& name, const Date& birth_date){
    name_ = name;
    birth_date_ = birth_date;
}

Date Person::get_birth_date() const{
    return birth_date_;
}

