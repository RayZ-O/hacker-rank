#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void shipToMax(multiset<int> &min_set, multiset<int> &max_set) {
    auto min_beg = min_set.begin();
    max_set.insert(*min_beg);
    min_set.erase(min_beg);
}

void shipToMin(multiset<int> &min_set, multiset<int> &max_set) {
    auto max_end = prev(max_set.end());
    min_set.insert(*max_end);
    max_set.erase(max_end);
}

void median(vector<char> s,vector<int> X) {
    multiset<int> min_set;
    multiset<int> max_set;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'r') {
            auto it1 = min_set.find(X[i]);
            auto it2 = max_set.find(X[i]);
            if (it1 == min_set.end() && it2 == max_set.end()) {
                cout << "Wrong!" << endl;
                continue;
            } else if (it2 != max_set.end()) {
                max_set.erase(it2);
                if (max_set.size() < min_set.size()) {
                    shipToMax(min_set, max_set);
                }
                if (max_set.empty()) {
                    cout << "Wrong!" << endl;
                    continue;
                }
            } else if (it1 != min_set.end()) {
                min_set.erase(it1);
                if (max_set.size() > 1 + min_set.size()) {
                    shipToMin(min_set, max_set);
                }
            }
        } else {
            if (max_set.empty()) {
                max_set.insert(X[i]);
            } else if (X[i] < *prev(max_set.end())) {
                max_set.insert(X[i]);
                if (max_set.size() > 1 + min_set.size()) {
                    shipToMin(min_set, max_set);
                }
            } else {
                min_set.insert(X[i]);
                if (max_set.size() < min_set.size()) {
                    shipToMax(min_set, max_set);
                }
            }
        }
        long m = *prev(max_set.end());
        if (max_set.size() > min_set.size()) {
            cout << m << endl;
        } else {
            cout << setprecision(11) << (m + *min_set.begin()) / 2.0 << endl;
        }
    }
}
int main(void){

//Helpers for input and output

   int N;
   cin >> N;

   vector<char> s;
    vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }

   median(s,X);
   return 0;
}
