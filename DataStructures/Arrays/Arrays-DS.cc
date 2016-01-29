#include <vector>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for (auto rit = arr.rbegin(); rit != arr.rend(); ++rit) {
       cout << *rit << " ";
    }
    return 0;
}
