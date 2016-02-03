#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    int last = 0;
    int max_dist = 0;
    sort(c.begin(), c.end());
    for (int i = 0; i < m; i++) {
        max_dist = max(max_dist, (c[i] - last) / 2);
        last = c[i];
    }
    max_dist = max(max_dist, c[0]);
    max_dist = max(max_dist, n - last - 1);
    cout << max_dist << endl;
    return 0;
}
