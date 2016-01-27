#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

enum class State {START, GOT_BRACKET, GOT_SLASH, GOT_EQUAL, START_TAG_NAME, END_TAG_NAME,
                  ATT_START, ATT_END, ATT_NAME, ATT_VALUE};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    string line;
    string cur;
    unordered_map<string, string> attrs;
     for (int i = 0; i <= n; i++) {
        getline(cin, line);
        State state = State::START;
        int name_beg = 0;
        for (int j = 0; j < line.size(); j++) {
            switch (line[j]) {
                case '<':
                    if (state == State::START) {
                        state = State::GOT_BRACKET;
                    }
                    break;
                case '>':
                    if (state == State::START_TAG_NAME) {
                        cur += line.substr(name_beg, j - name_beg) + '.';
                        state = State::START;
                    } else if (state == State::END_TAG_NAME) {
                        cur.erase(cur.end() - 1 - j + name_beg , cur.end());
                        state = State::START;
                    } else if (state == State::ATT_START) {
                        state = State::START;
                    }
                    break;
                case '/':
                    if (state == State::GOT_BRACKET) {
                        state = State::GOT_SLASH;
                    }
                    break;
                case ' ':
                    if (state == State::START_TAG_NAME) {
                        cur += line.substr(name_beg, j - name_beg) + '.';
                        state = State::ATT_START;
                    } else if (state == State::END_TAG_NAME) {
                        cur.erase(cur.end() - 1 - j + name_beg, cur.end());
                        state = State::START;
                    } else if (state == State::ATT_NAME) {
                        cur.back() = '~';
                        cur += line.substr(name_beg, j - name_beg);
                        state = State::ATT_END;
                    }
                    break;
                case '\"':
                    if (state == State::GOT_EQUAL) {
                        name_beg = j + 1;
                        state = State::ATT_VALUE;
                    } else if (state == State::ATT_VALUE) {
                        attrs[cur] = line.substr(name_beg, j - name_beg);
                        int k = cur.size() - 1;
                        while (cur[k] != '~') {
                            k--;
                        }
                        cur.erase(cur.begin() + k, cur.end());
                        cur.push_back('.');
                        state = State::ATT_START;
                    }
                    break;
                case '=':
                    if (state == State::ATT_END) {
                        state = State::GOT_EQUAL;
                    }
                default:
                    if (isalnum(line[j]) || line[j] == '_') {
                        if (state == State::GOT_BRACKET) {
                            name_beg = j;
                            state = State::START_TAG_NAME;
                        } else if (state == State::GOT_SLASH) {
                            name_beg = j;
                            state = State::END_TAG_NAME;
                        } else if (state == State::ATT_START) {
                            name_beg = j;
                            state = State::ATT_NAME;
                        }
                    }
                    break;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        getline(cin, line);
        if (attrs.count(line)) {
            cout << attrs[line] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
