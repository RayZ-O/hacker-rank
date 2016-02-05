#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int val;
    string s;
    vector<pair<int, string>> v;
    int count[100] = {0};
    for (int i = 0; i < n; i++) {
        cin >> val >> s;
        count[val]++;
        v.emplace_back(val, s);
    }
    int helper[100] = {0};
    int less = 0;
    for (int i = 0; i < 100; i++) {
        helper[i] = less;
        less += count[i];
    }
    vector<string> output(n);
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            output[helper[v[i].first]++] = "-";
        } else {
            output[helper[v[i].first]++] = v[i].second;
        }
    }
    for (auto &e : output) {
        cout << e << " ";
    }
    return 0;
}
