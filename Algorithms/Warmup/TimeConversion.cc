#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    string ap = time.substr(time.size() - 2, 2);
    int hour = stoi(time.substr(0, 2));
    if (ap == "AM") {
        cout << setw(8) << setfill('0') << to_string(hour % 12) + time.substr(2, 6) << endl;
    } else {
       cout << to_string(hour % 12 + 12) + time.substr(2, 6) << endl;
    }
    return 0;
}
