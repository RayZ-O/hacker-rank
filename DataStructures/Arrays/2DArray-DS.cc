#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max_sum = -64;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            int sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]
                                    + arr[i][j]
                    + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
            max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum << endl;
    return 0;
}
