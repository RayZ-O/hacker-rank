#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


int main(){
    string s;
    cin >> s;
    int L = s.size();
    int m = floor(sqrt(L));
    int col = m + (m * m < L ? 1 : 0);
    int row = m + (m * col < L ? 1 : 0);
    vector<vector<char>> vv(row, vector<char>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            vv[i][j] = s[i*col+j];
        }
    }
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (vv[i][j]) {
                cout << vv[i][j];
            }
        }
        cout << " ";
    }
    return 0;
}
