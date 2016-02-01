#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    getline(cin, s);
    int count[26] = {0};
    for (char c : s) {
        if (islower(c)) {
            count[c-'a']++;
        }
        if (isupper(c)) {
            count[c-'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (0 == count[i]) {
            cout << "not pangram" << endl;
            return 0;
        }
    }
    cout << "pangram" << endl;
    return 0;
}
