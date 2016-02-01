#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countTopics(string &s, string &t, int m) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1' || t[i] == '1') {
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    int max_topic = 0;
    int num_team = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = countTopics(topic[i], topic[j], m);
            if (count == max_topic) {
                num_team++;
            } else if (count > max_topic) {
                max_topic = count;
                num_team = 1;
            }
        }
    }
    cout << max_topic << endl;
    cout << num_team << endl;
    return 0;
}
