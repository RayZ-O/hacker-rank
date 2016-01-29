#include <iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int h = 1;
        for (int i = 0; i < n; i++) {
            h += i % 2 ? 1 : h;
        }
        cout << h << endl;
    }
    return 0;
}
