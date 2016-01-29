#include <iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int n3 = 0, c5 = n / 3;
        while (c5 >= 0) {
            n3 = (n - c5 * 3);
            if (0 == n3 % 5) {
                cout << string(c5 * 3, '5') + string(n3, '3') << endl;
                break;
            }
            c5--;
        }
        if (c5 < 0) {
            cout << -1 << endl;
        }
    }
    return 0;
}
