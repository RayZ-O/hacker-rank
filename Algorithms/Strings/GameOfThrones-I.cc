#include <iostream>
#include <string>
using namespace std;


int main() {
    string s;
    cin>>s;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string
    int dict[26] = {0};
    for (char c : s) {
        dict[c-'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (dict[i] % 2 != 0) {
            cnt++;
        }
    }
    if(cnt > 1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
