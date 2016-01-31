#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        }
        if (isupper(s[i])) {
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
        }
    }
    cout << s << endl;
    return 0;
}
