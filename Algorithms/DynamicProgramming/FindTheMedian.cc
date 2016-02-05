#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> &v, int l, int r) {
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (v[j] < v[r]) {
            swap(v[++i], v[j]);
        }
    }
    swap(v[++i], v[r]);
    return i;
}

int kthElement(vector<int> &v, int l, int r, int k) {
    if (l == r) {
        return v[l];
    }
    int p = partition(v, l, r);
    int i = p - l + 1;
    if (k == i) {
        return v[p];
    } else if (k < i) {
        return kthElement(v, l, p - 1, k);
    } else {
        return kthElement(v, p + 1, r, k - i);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    double a = kthElement(v, 0, n - 1, n / 2 + 1);
    if (n % 2 == 0) {
        a = (a + kthElement(v, 0, n - 1, n / 2 )) / 2.0;
    }
    cout << a << endl;
    return 0;
}
