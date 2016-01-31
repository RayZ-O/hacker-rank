#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        bool found = false;
        for (int i = 0; i <= R - r; i++) {
            for (int j = 0; j <= C - c; j++) {
                int k = 0;
                while (k < r) {
                    if (G[k+i].substr(j, c) != P[k]) {
                        break;
                    }
                    k++;
                }
                if (k == r) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}
