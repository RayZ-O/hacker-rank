#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    int lastans = 0;
    vector<vector<int>> vv(n);
    while (q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (1 == t) {
            vv[(x ^ lastans) % n].push_back(y);
        } else {
            int size = vv[(x ^ lastans) % n].size();
            int elem = vv[(x ^ lastans) % n][y % size];
            cout << elem << endl;
            lastans = elem;
        }
        q--;
    }
    return 0;
}
