#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    k %= n;
    int idx;
    for (int i = 0; i < q; i++) {
        cin >> idx;
        cout << v[(idx+n-k)%n] << endl;
    }
    return 0;
}
