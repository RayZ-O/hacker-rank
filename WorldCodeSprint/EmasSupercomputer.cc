#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m;
int n;

int findCross(vector<vector<char>>& board, int i, int j, bool fst) {
    int len = 0;
    while (i - len >= 0  && i + len < m && j - len >= 0 && j + len < n
           && board[i-len][j] == 'G' && board[i+len][j] == 'G'
           && board[i][j-len] == 'G' && board[i][j+len] == 'G') {
        if (fst) {
            board[i-len][j] = 'O';
            board[i+len][j] = 'O';
            board[i][j-len] = 'O';
            board[i][j+len] = 'O';
        }
        len++;
    }
    return len;
}

void recover(vector<vector<char>>& board, int len, int i, int j) {
    for (int l = 0; l < len; l++) {
        board[i-l][j] = 'G';
        board[i+l][j] = 'G';
        board[i][j-l] = 'G';
        board[i][j+l] = 'G';
    }
}

int maxProduct(vector<vector<char>>& board, int i, int j) {
     int len1 = findCross(board, i, j, true);
     int len2 = 0;
     for (int s = 0; s < m; s++) {
        for (int t = 0; t < n; t++) {
            len2 = max(len2, findCross(board, s, t, false));
        }
     }
     recover(board, len1, i, j);
     return (1 + 4 * (len1 - 1)) * (1 + 4 * (len2 - 1));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int max_product = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') {
                max_product = max(maxProduct(board, i, j), max_product);
            }
        }
    }
    cout << max_product << endl;
    return 0;
}
