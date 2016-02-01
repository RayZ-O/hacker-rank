#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s, t;
    cin >> s >> t;
    int dict[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        dict[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        dict[t[i]-'a']--;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += abs(dict[i]);
    }
    cout << sum << endl;
    return 0;
}
