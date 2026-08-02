#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

class Student : public Person{
    public:
        Student(int id, const string& name, const string& course);
        
        const string& course() const;
        string to_string() const;

    private:
        string course_;
};

Student::Student(int id, const string& name, const string& course):Person(id, name){
    course_ = course;
}

const string& Student::course() const{
    return course_;
}

string Student::to_string() const{
    ostringstream out;
    out << id() << '/' << name() << '/' << course_;
    return out.str();
}

class ErasmusStudent : public Student{
    public:
        ErasmusStudent(int id, const string& name, const string& course, const string& country);

        const string& country() const;

        string to_string() const;

    private:
        string country_;
};

ErasmusStudent::ErasmusStudent(int id, const string& name, const string& course, const string& country):Student(id, name, course){
    country_ = country;
}

const string& ErasmusStudent::country() const{
    return country_;
}

string ErasmusStudent::to_string() const{
    ostringstream out;
    out << id() << '/' << name() << '/' << course() << '/' << country_;
    return out.str();
}

int main(){
    Person p(125, "Marie Curie");
    Student s(126, "Ada Lovelace", "LEIC");
    ErasmusStudent es(127, "Grace Hopper", "LXPTO", "United States");
    cout << p.to_string() << ' ' << s.to_string() << ' ' << es.to_string() << '\n';

    return 0;
}