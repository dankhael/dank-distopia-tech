#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
    cout << "[ ";
    for (const auto& e : count) {
        cout << e.first << ":" << e.second << ' ';
    }

    cout << "]\n";
}
bool bigger(pair<string, size_t> a, pair<string, size_t> b){
    if (a.first < b.first){
        return true;
    }
    else{
        return false;
    }
}


void count_words(const string& str, vector<pair<string, size_t>>& count){
    
    char ch;
    string m; 
    pair<string, size_t> n;
    bool flag = true;

    istringstream iss(str);

    while (iss >> m){
        for (size_t j = 0; j < m.length(); j++){
            ch = tolower(m[j]);
            m[j] = ch;
        }   

        int l = count.size();

        for (int i = 0; i < l; i++){
            if (count[i].first == m){
                count[i].second += 1;
                flag = false;
            }
        }
        if(flag){
            n.first = m;
            n.second = 1;
            count.push_back(n);
        }
        flag = true;
    } 

    sort(count.begin(), count.end(), bigger);

}


int main(){
    string s = "If you want to buy  buy  if you don't want to buy  bye bye";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count);


    return 0;
}