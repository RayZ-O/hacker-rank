#include <vector>
#include <iostream>
using namespace std;

const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool canPass(vector<string> &forest, int r, int c, int n, int m) {
    return r >= 0 && r < m && c >= 0 && c < n && forest[r][c] != 'X';
}

bool dfs(vector<string> &forest, int r, int c, int n, int m, int &cnt) {
    if (forest[r][c] == '*') {
        return true;
    }
    forest[r][c] = 'X';

    int ways = 0;
    for (auto d : dirs) {
        if (canPass(forest, r + d.first, c + d.second, n, m)) {
            ways++;
        }
    }

    for (auto d : dirs) {
        int x = r + d.first;
        int y = c + d.second;
        if (canPass(forest, x, y, n, m) && dfs(forest, x, y, n, m, cnt)) {
            if (ways > 1) {
                cnt++;
            }
            return true;
        }

    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        int n, m, k;
        cin >> n >> m;
        string s;
        vector<string> forest(n);
        for (int i = 0; i < n; i++) {
            cin >> forest[i];
        }
        cin >> k;
        bool impressed;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] == 'M') {
                    int count = 0;
                    dfs(forest, i, j, m, n, count);
                    impressed = count == k;
                    break;
                }
            }
        }
        cout << (impressed ? "Impressed" : "Oops!") << endl;
        t--;
    }
    return 0;
}
