#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    vector<int> C(N);
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    sort(C.begin(), C.end(), greater<int>());
    int result = 0;
    int x = 1;
    while (N > 0) {
        for (int i = 0; i < min(N, K); i++) {
            result += x * C[(x - 1) * K + i];
        }
        x++;
        N -= K;
    }
    cout << result << "\n";

    return 0;
}
