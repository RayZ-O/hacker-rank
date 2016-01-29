
#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, a, b;
    cin >> t;
    while (t) {
        cin >> a >> b;
        cout << floor(sqrt(b)) - ceil(sqrt(a)) + 1 << endl;
        t--;
    }
    return 0;
}
