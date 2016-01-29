#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        int on_time = 0;
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
           if (a[a_i] <= 0) {
               on_time++;
           }
        }
        cout << (on_time >= k ? "NO" : "YES") << endl;
    }
    return 0;
}
