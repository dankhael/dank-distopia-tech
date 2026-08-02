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
    int t;
    bool flag = true;

    if ((n % 2 == 0) || (n > t_1) || (n > t_2)){
        return false;
    }
    else{
        int m = (n - 1) / 2;

        for (int i = 0; i < t_1; i++){
            for (int j = 0; j < t_2; j++){

                for (int k = -m; k <= m; k++){
                    for (int l = -m; l <= m; l++){

                        int neighbourhood_line = i + k;
                        int neighbourhood_col = j + l;


                        if((neighbourhood_line > 0) && (neighbourhood_col > 0) && (neighbourhood_line < t_1) && (neighbourhood_col < t_2) && (l != 0 || k != 0)){
                            if(flag){
                                t = v[k][l];
                                flag = false;
                            }
                            else{
                                if (v[k][l] > t){
                                    t = t = v[k][l];
                                }
                            }
                        }
                        v[i][j] = t;
                        flag = true;
                    }
                }
                
                
            }
        }

        return true;
    }
    
}


int main(){
    vector<vector<int>> v = 
    { {1,2,3},
      {4,5,6},
      {7,8,9} };

  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl << endl;



  return 0;
}