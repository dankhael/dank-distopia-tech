#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end){
    ostringstream res;

    res << "[ ";

    Itr it = start;
    while (it != end){
        res << *it << " ";
        ++it;
    }
    res << "]";

    return res.str();
}


template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b){
    int res = 0;
    
    Itr it = start;
    while (it != end){
        if (*it == a){
            *it = b;
            ++res;

        }
         ++it;
    }

    return res;
}

int main(){
    vector<int> v { 1, 2, 3, 3, 4 };
    cout << replace(v.begin(), v.end(), 3, 0) << ' ' << to_string(v.cbegin(), v.cend()) << '\n';


    return 0;

}