#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &arr, int l, int r) {
    if (l >= r) {
        return;
    }
    vector<int> a, b;
    int pivot = arr[l];
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < pivot) {
            a.push_back(arr[i]);
        }
        if (arr[i] > pivot) {
            b.push_back(arr[i]);
        }
    }
    int j = l;
    for (int i : a) {
        arr[j++] = i;
    }
    int p = j;
    arr[j++] = pivot;
    for (int i : b) {
        arr[j++] = i;
    }
    partition(arr, l, p - 1);
    partition(arr, p + 1, r);
    for (int j = l; j <= r; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void quickSort(vector<int> &arr) {
   partition(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
