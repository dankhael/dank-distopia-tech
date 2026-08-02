#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

void sort(){}



int main(){
  vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n';


  return 0;
}