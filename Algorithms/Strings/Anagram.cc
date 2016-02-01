#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s;
        cin >> s;
        int n = s.size();
        if (n % 2) {
            cout << -1 << endl;
        } else {
            int dict[26] = {0};
            for (int i = 0; i < n/2; i++) {
                dict[s[i]-'a']++;
            }
            for (int i = n/2; i < n; i++) {
                dict[s[i]-'a']--;
            }
            int num = 0;
            for (int i = 0; i < 26; i++) {
                if (dict[i] > 0) {
                    num += dict[i];
                }
            }
            cout << num << endl;
        }
        t--;
    }
    return 0;
}
