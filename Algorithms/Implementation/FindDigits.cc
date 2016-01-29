#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int cur = n;
        int count = 0;
        while (cur) {
            int d = cur % 10;
            if (d != 0 && 0 == n % d) {
                count++;
            }
            cur /= 10;
        }
        cout << count << endl;
    }
    return 0;
}
