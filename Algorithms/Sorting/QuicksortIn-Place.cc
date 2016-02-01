#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int partition(vector<int> &arr, int l, int r) {
    int i = -1;
    for (int j = 0; j < r; j++) {
        if (arr[j] < arr[r]) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[r]);
    return i;
}

void qSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        print(arr);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, r);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> arr;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    qSort(arr, 0, n - 1);
    return 0;
}
