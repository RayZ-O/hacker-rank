#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &arr, int l, int r, int &cnt) {
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < arr[r]) {
            swap(arr[++i], arr[j]);
            cnt++;
        }
    }
    cnt++;
    swap(arr[++i], arr[r]);
    return i;
}

void qSort(vector<int> &arr, int l, int r, int &cnt) {
    if (l < r) {
        int k = partition(arr, l, r, cnt);
        qSort(arr, l, k - 1, cnt);
        qSort(arr, k + 1, r, cnt);
    }
}

void iSort(vector<int> &arr, int &cnt) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        cnt += i - 1 - j;
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
    vector<int> u = v;
    int qcnt = 0;
    int icnt = 0;
    iSort(v, icnt);
    qSort(u, 0, u.size() - 1, qcnt);
    cout << icnt - qcnt << endl;
    return 0;
}
