#include <iostream>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, a, b;
    cin >> t;
    while (t) {
        cin >> n >> a >> b;
        set<int> prev, cur;
        prev.insert(0);
        while (--n) {
            for (auto i : prev) {
                cur.insert(i + a);
                cur.insert(i + b);
            }
            prev.swap(cur);
            cur.clear();
        }
        for (auto i : prev) {
            cout << i << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}
