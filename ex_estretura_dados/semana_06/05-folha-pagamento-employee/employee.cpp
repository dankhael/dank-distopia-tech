#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"


void SalariedEmployee::calculate_net_pay(){
  set_net_pay(salary_);
}

void HourlyEmployee::calculate_net_pay(){
  set_net_pay(hours_ * wage_rate_);
}

void read_hours_worked(vector<Employee*> &employees){

  for (size_t i = 0; i < employees.size();i++){
    double t;
    HourlyEmployee* h_employee = dynamic_cast <HourlyEmployee*> (employees.at(i));
    if (h_employee != nullptr){
      cin >> t;
      h_employee->set_hours(t);
    }
  }
}

void calculate_pay(vector<Employee*>& employees){

  for (size_t i = 0; i < employees.size(); i++){
      employees[i]->calculate_net_pay();
  }
}

void print_checks(const vector<Employee*>& employees){
  for (size_t i = 0; i < employees.size(); i++){
      if (i == 0){
        cout << "|";
      }
      cout << " ";
      employees[i]->print_check();
      cout << " |";
  }
}

int main(){
  vector<Employee*> employees = {
    new SalariedEmployee("John", 2000),
    new HourlyEmployee("Mary", 10) };
  read_hours_worked(employees);
  calculate_pay(employees);
  print_checks(employees);
  for (const auto& e : employees) delete e;

  return 0;
}
