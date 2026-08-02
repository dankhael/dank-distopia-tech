#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool bigger(pair <string, size_t> a, pair <string, size_t> b){
  return a.first < b.first;
}


void count_words(const string& str, map<string, size_t>& count){
    string m;
    map<string, size_t>::const_iterator it;
    
    istringstream iss(str);

    while (iss >> m){
        transform(m.begin(), m.end(), m.begin(), ::tolower);

        it = count.find(m);

        if (it != count.end()){
            count[m] += 1;
        }
        else{
            count.insert({m,1});
        }
    }
       // Create a vector of pairs from the map
    vector<pair<string, size_t>> vec(count.begin(), count.end());

    // Sort the vector by key
    sort(vec.begin(), vec.end(), bigger);

    // Update the map with the sorted pairs
    count.clear();
    for (const auto& p : vec) {
        count[p.first] = p.second;
    }
}


void show_map(const map<string, size_t>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

int main(){
  string s = "If you want to buy  buy  if you don't want to buy  bye bye";
  map<string, size_t> count; 
  count_words(s, count);
  show_map(count);

  return 0;
}