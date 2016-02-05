#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF (INT_MAX / 2)

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> D(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        D[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        D[x-1][y-1] = r;
    }
    for (int k = 0; k < n; k++) {
        auto Dn = D;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Dn[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
        D.swap(Dn);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (D[a-1][b-1] == INF ? -1 : D[a-1][b-1]) << endl;
    }
    return 0;
}
