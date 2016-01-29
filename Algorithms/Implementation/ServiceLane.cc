#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
        int type = 3;
        for (int k = i; k <= j; k++) {
            type = min(type, width[k]);
            if (type == 1) {
                break;
            }
        }
        cout << type << endl;
    }
    return 0;
}
