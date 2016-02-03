#include <iostream>
using namespace std;

void count(int A, int B, int C, int D, char last, int& cnt) {
    if (A < 0 || B < 0 || C < 0 || D < 0) {
        return;
    }
    if (A == 0 && B == 0 && C == 0 && D == 0) {
        cnt++;
        return;
    }
    if (last == 'R') {
        count(A - 1, B, C, D, 'R', cnt);
        count(A, B - 1, C, D, 'B', cnt);
    } else {
        count(A, B, C - 1, D, 'B', cnt);
        count(A, B, C, D - 1, 'R', cnt);
    }
}

int main(){
    int A;
    int B;
    int C;
    int D;
    cin >> A >> B >> C >> D;
    int cnt = 0;
    count(A, B, C, D, 'R', cnt);
    count(A, B, C, D, 'B', cnt);
    cout << cnt << endl;
    return 0;
}
