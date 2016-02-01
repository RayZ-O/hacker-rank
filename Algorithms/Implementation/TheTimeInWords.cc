#include <vector>
#include <iostream>
using namespace std;


int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    vector<string> v{"", "one", "two", "three", "four", "five", "six", "seven",
                     "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "", "sixteen", "sevent een", "eighteen", "nineteen", "twenty",
                     "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
                     "twenty six", "twenty seven", "twenty eight", "twenty nine"};

    string time;
    if (m == 0) {
        time += v[h] + " o\' clock";
    } else {
        int n = m > 30 ? 60 - m : m;
        if (n == 15) {
            time += "quarter ";
        } else if (n == 30) {
            time += "half ";
        } else {
            time += v[n] + " minute" + (n > 1 ? "s " : " ");
        }

        time += (m > 30 ? "to " + v[h % 12 + 1] : "past " + v[h]) ;
    }
    cout << time << endl;
    return 0;
}
