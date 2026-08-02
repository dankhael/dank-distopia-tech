#include <iostream>
#include <vector>

using namespace std;

void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}



bool max_filter(vector<vector<int>> &v, int n){
    int t_1 = v.size();
    int t_2 = v[0].size();

    if (n % 2 == 0 || n > t_1 || n > t_2){
        return false;
    }
    else{
        int m = (n - 1) / 2;

        for (int i = m; i < t_1 - m; i++){
            for (int j = m; j < t_2 - m; j++){
                int max_val = v[i][j];

                for (int k = -m; k <= m; k++){
                    for (int l = -m; l <= m; l++){
                        int neighbor_row = i + k;
                        int neighbor_col = j + l;

                        if (k == 0 && l == 0) continue;
                        if (neighbor_row < 0 || neighbor_row >= t_1) continue;
                        if (neighbor_col < 0 || neighbor_col >= t_2) continue;

                        max_val = max(max_val, v[neighbor_row][neighbor_col]);
                    }
                }

                v[i][j] = max_val;
            }
        }

        return true;
    }
}



int main(){
    vector<vector<int>> v = { {1,2,3}, {4,5,6}, {7,8,9} };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl << endl;



  return 0;
}
