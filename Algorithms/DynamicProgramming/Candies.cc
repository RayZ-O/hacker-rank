#include <vector>
#include <iostream>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> rating(n);
    for (int i = 0; i < n; i++) {
        cin >> rating[i];
    }
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++) {
        if (rating[i] > rating[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    for (int i = n - 2 ; i >= 0; i--) {
        if (rating[i] > rating[i+1] && candies[i] <= candies[i+1]) {
            candies[i] = candies[i+1] + 1;
        }
    }
    cout << accumulate(candies.begin(), candies.end(), 0) << endl;
    return 0;
}
