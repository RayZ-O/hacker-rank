#include <iostream>
using namespace std;


int main(){
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i < S.size(); i += 3) {
        if (S[i] != 'S') {
            count++;
        }
        if (S[i+1] != 'O') {
            count++;
        }
        if (S[i+2] != 'S') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
