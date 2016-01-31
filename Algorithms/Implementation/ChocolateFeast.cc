#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int count = n / c;
        int remain = count;
        while (remain >= m) {
            int exchange = remain / m;
            count += exchange;
            remain = remain % m + exchange;
        }
        cout << count << endl;
    }
    return 0;
}
