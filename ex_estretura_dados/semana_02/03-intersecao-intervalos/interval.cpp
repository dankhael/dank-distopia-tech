#include <iostream>
#include "interval.h"

using namespace std;
void troca (interval &a, interval &b){
    char x;
    char y;
    char w;
    char z;

    x = a.start.h;
    y = a.start.m;
    w = a.end.h;
    z = a.end.m;


    a.start.h = b.start.h;
    a.start.m = b.start.m;
    a.end.h = b.end.h;
    a.end.m = b.end.m;

    b.start.h = x;
    b.start.m = y;
    b.end.h = w;
    b.end.m = z;  

}

void atribuir (interval &a, interval &b){

    a.start.h = b.start.h;
    a.start.m = b.start.m;
    a.end.h = b.end.h;
    a.end.m = b.end.m;
}

bool maior  (time_of_day a, time_of_day b){

    if (a.h > b.h ){
        return true;
    }
    else if (a.h == b.h){
        if (a.m >= b.m){
            return true;
        }

    }
    return false;
}

interval intersection(interval a, interval b){


interval res;

res.start.h = 0;
res.start.m = 0;
res.end.h = 0;
res.end.m = 0;

    if (b.start.h > a.start.h){
            troca(a,b);
     
    }
    else if (b.start.h == a.start.h){
        if (b.start.m > a.start.m){
            troca(a,b);
        }
    }

    if (maior(a.start,b.end))
    {
        return res;
    }
    else if (maior(b.end, a.end)){
        
        atribuir(res,a);
        return res;
    }
    else{

        res.start.h = a.start.h;
        res.start.m = a.start.m;
        res.end.h = b.end.h;
        res.end.m = b.end.m;

        return res;
    }
}



int main(){


cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n';

return 0;
}