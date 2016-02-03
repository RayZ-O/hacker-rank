#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int dfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
    int count = 1;
    grid[r][c] = 'X';
    for (auto d : dirs) {
        int x = r + d.first;
        int y = c + d.second;
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
            count += dfs(grid, x, y, m, n);
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int max_count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                max_count = max(max_count, dfs(grid, i, j, m, n));
            }
        }
    }
    cout << max_count << endl;
    return 0;
}
