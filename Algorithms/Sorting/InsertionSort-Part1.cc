#include <vector>
#include <iostream>
using namespace std;

void print(vector<int>&  ar) {
    for (int i : ar) {
        cout << i << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>  ar) {
    int temp = ar.back();
    int i = ar.size() - 2;
    while (i >= 0 && ar[i] > temp) {
        ar[i+1] = ar[i];
        print(ar);
        i--;
    }
    ar[i+1] = temp;
    print(ar);
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
       int _ar_tmp;
       cin >> _ar_tmp;
       _ar.push_back(_ar_tmp);
    }
    insertionSort(_ar);
    return 0;
}
