#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int *arr[n];
    for (int i = 0; i < n; i++) {
        int k, s;
        cin >> k;
        arr[i] = new int[k];
        for (int j = 0; j < k; j++) {
            cin >> s;
            arr[i][j] = s;
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }
    return 0;
}
