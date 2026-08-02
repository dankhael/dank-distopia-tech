#include <iostream>
#include "interval.h"

using namespace std;

bool pertence (time_of_day t, const interval a){
    bool res = false;


    if (a.start.h == a.end.h){
        if (t.h == a.start.h){
            if (t.m >= a.start.m && t.m < a.end.m){
                res = true;
            }
        }
    }
    else{
        if (t.h > a.start.h){
            if (t.h < a.end.h){
                res = true;
            }
            else if (t.h == a.end.h){
                if (t.m < a.end.m ){
                    res = true;
                }
            }
            
        }
        if (t.h == a.start.h){
            if (t.m >= a.start.m){
                res = true;
            }
        }
    }
    
    return res;
}

bool bigger(time_of_day a, time_of_day b){

    bool res = false;

    if (b.h > a.h){
        res = true;
    }
    else if (a.h == b.h){
        if (b.m > a.m){
            res = true;
        }
    }

    return res;

}


int search_intervals(time_of_day t, const interval a[], int n, interval& u){

    bool flag = false;
    u.start = t;
    u.end = t;
    interval m;
    int res;


    for (int i = 0; i < n; i++){
        if(pertence(t, a[i])){
            if (flag){

                m.start = a[i].start;
                m.end = a[i].end;

                if (bigger(m.start, u.start)){
                    u.start = m.start;
                }
                if (bigger(u.end, m.end)){
                    u.end = m.end;
                }
            } 
            else{
                flag = true;
                u.start = a[i].start;
                u.end = a[i].end;
            }
        }   

    }
    
    res = (u.end.h - u.start.h) * 60 + (u.end.m - u.start.m);

    return res;
}


int main(){

  const int n = 5;
  const time_of_day t = { 15, 15 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } }, 
                  { { 15, 10 }, { 16, 10 } }, 
                  { {  9, 30 }, { 15, 15 } }, 
                  { {  9, 45 }, { 15, 16 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n';


  return 0;

}