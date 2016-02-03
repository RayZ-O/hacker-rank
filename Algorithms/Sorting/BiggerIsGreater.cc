#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s;
        cin >> s;
        if (next_permutation(s.begin(), s.end())) {
            cout << s << endl;
        } else {
            cout << "no answer" << endl;
        }
        t--;
    }
    return 0;
}
