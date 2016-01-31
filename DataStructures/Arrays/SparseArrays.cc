#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n;
    string s;
    unordered_map<string, int> um;
    for (int i = 0; i < n; i++) {
        cin >> s;
        um[s]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << um[s] << endl;
    }
    return 0;
}
