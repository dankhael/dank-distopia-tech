#include <iostream>
#include <string>
#include <algorithm> 
#include "smatrix.h"

using namespace std;

bool less_than(sm_entry a, sm_entry b){
    bool res = false;

    if (a.row < b.row){
      res = true;
    }
    if (a.row == b.row){
      if (a.col < b.col){
        res = true;
      }
    }
  return res;
}

void sum(const smatrix& a, const smatrix& b, smatrix& r){

  bool flag = true;
  sm_entry res;
  int t;


    for (sm_entry x: a){
      for (sm_entry y:b){
        if (x.row == y.row && x.col == y.col){
          flag =false;
          t = x.value + y.value;

          if (t != 0){
            res.row = x.row;
            res.col = x.col;
            res.value = t;

            r.push_back(res);
          }
          break;

        }
      }
    if (flag){
      r.push_back(x);
    }
    flag = true;
      }

flag = true;

    for(sm_entry x:b){
      for(sm_entry y: a){
        if (x.row == y.row && x.col == y.col){
          flag = false;
          break;
        }
        
      }
      if (flag){
          r.push_back(x);
        }
        flag = true;
    }

  sort(r.begin(),r.end(), less_than);
  

}


int main(){
  smatrix r;
  sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
      r);
  print(r);

  return 0;
}