#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        cin >> b >> w;
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        long cost = 0L;
        if (x < y) {
            cost += x * b;
            cost += (x + z < y ? (x + z) : y) * w;
        } else {
            cost +=  y * w;
            cost += (y + z < x ? (y + z) : x) * b;
        }
        cout << cost << endl;
    }
    return 0;
}
