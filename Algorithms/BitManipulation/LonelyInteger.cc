#include <limits>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int lonelyinteger(vector<int> a) {
    return accumulate(a.begin(), a.end(), 0, bit_xor<int>());

}

int main() {
    int res;

    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = lonelyinteger(_a);
    cout << res;

    return 0;
}
