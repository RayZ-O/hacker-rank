#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s;
        cin >> s;
        int count = 0;
        char prev = 'X';
        for (char c : s) {
            if (c != prev) {
                prev = c;
            } else {
                count++;
            }
        }
        cout << count << endl;
        t--;
    }
    return 0;
}
