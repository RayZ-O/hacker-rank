#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool inBound(int i, int j, int l, int r, int t, int b) {
    return j >= l && j < r && i >= t && i < b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n, R;
    cin >> m >> n >> R;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> res(m, vector<int>(n, 0));
    int l = 0, r = n, t = 0, b = m;
    while (l < r && t < b) {
        int len = 2 * (r - l) + 2 * (b - t - 2);
        int rm = R % len;
        int p = l, q = t, d = 0;
        while (rm--) {
            if (!inBound(p + dirs[d].first, q + dirs[d].second, l, r, t, b)) {
                d = (d+1) % 4;
            }
            p += dirs[d].first;
            q += dirs[d].second;
        }
        int i = l, j = t, k = 0;
        while (len--) {
            res[i][j] = matrix[p][q];
            if (!inBound(i + dirs[k].first, j + dirs[k].second, l, r, t, b)) {
                k = (k+1) % 4;
            }
            i += dirs[k].first;
            j += dirs[k].second;
            if (!inBound(p + dirs[d].first, q + dirs[d].second, l, r, t, b)) {
                d = (d+1) % 4;
            }
            p += dirs[d].first;
            q += dirs[d].second;
        }
        l++;
        r--;
        t++;
        b--;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
