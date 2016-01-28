#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int lt = 0, eq = 0, gt = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       arr[arr_i] > 0 ? gt++ : arr[arr_i] == 0 ? eq++ : lt++;
    }
    double dn = static_cast<double>(n);
    cout.precision(6);
    cout.setf(ios::fixed, ios::floatfield);
    cout << gt / dn << endl;
    cout << lt / dn << endl;
    cout << eq / dn << endl;
    return 0;
}
