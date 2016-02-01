#include <vector>
#include <iostream>
using namespace std;
void partition(vector<int> ar) {
    int pivot = ar[0];
    int i = ar.size();
    for (int j = ar.size() - 1; j > 0; j--) {
        if (ar[j] > pivot) {
            swap(ar[--i], ar[j]);
        }
    }
    swap(ar[--i], ar[0]);
    for (auto i : ar) {
        cout << i << " ";
    }
    cout << endl;
}
int main(void) {
    vector<int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    partition(_ar);

    return 0;
}
