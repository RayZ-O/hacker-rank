#include <unordered_set>
#include <limits>
#include <vector>
#include <iostream>
using namespace std;
/* Head ends here */

int pairs(vector<int> a, int k) {
    int ans = 0;
    unordered_set<int> dict;
    for (int i : a) {
        if (dict.count(i-k)) {
            ans++;
        }
        if (dict.count(i+k)) {
            ans++;
        }
        dict.insert(i);
    }
    return ans;
}

/* Tail starts here */
int main() {
    int res;

    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = pairs(_a,_k);
    cout << res;

    return 0;
}
