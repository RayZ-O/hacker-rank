#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    sort(arr.begin(), arr.end());
    int beg = 0, size = arr.size();
    while (beg < size) {
        cout << size - beg << endl;
        int i = beg + 1;
        while (i < size && arr[i] == arr[beg]) {
            i++;
        }
        beg = i;
    }
    return 0;
}
