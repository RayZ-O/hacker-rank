#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count[100] = {0};
    int n;
    cin >> n;
    int val;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> val >> s;
        count[val]++;
    }
    int L = 0;
    for (int i = 0; i < 100; i++) {
        L += count[i];
        cout << L << " ";
    }
    return 0;
}
