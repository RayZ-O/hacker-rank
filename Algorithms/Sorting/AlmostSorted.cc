#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSorted(vector<int> &v, int l, int r, bool reverse) {
    for (int i = l + 1; i <= r; i++) {
        if (v[i-1] < v[i] == reverse) {
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] > v[i+1]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << "yes" << endl;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] < v[i-1]) {
            r = i;
            break;
        }
    }
    if ((l == 0 || v[r] > v[l-1]) && (r == n - 1 || v[l] < v[r+1])) {
        if (isSorted(v, l+1, r-1, false)) {
            cout << "yes\n" << "swap " << l + 1 << " "<< r + 1 << endl;
            return 0;
        } else if (isSorted(v, l, r, true)) {
            cout << "yes\n" << "reverse " << l + 1 << " "<< r + 1<< endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
