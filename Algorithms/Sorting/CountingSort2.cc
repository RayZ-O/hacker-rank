#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count[100] = {0};
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        count[val]++;
    }
    for (int i = 0; i < 100; i++) {
        while (count[i]--) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
