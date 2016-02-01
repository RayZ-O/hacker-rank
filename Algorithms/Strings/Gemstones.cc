#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int dict[26] = {0};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ch[26] = {0};
        for (char c : s) {
            ch[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (ch[i]) {
                dict[i]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (dict[i] == n) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
