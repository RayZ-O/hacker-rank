#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    bool is_end;
    Node* child[11];
    Node() : is_end(false) {
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
    Node *root;
public:
    Trie() : root(new Node) {}

    void insert(string& s) {
        Node *node = root;
        for (char c : s) {
            int num = c -'0';
            if (!node->child[num]) {
                node->child[num] = new Node;
            }
            node = node->child[num];
        }
        node->is_end = true;
    }

    int count(string &s, int beg) {
        int count = 0;
        Node *node = root;
        int i;
        for (i = beg; i < s.size(); i++) {
            if (node->is_end) {
                count++;
            }
            int num = s[i] - '0';
            if (!node->child[num]) {
                break;
            }
            node = node->child[num];
        }
        if (i == s.size() && node->is_end) {
            count++;
        }
        return count;
    }
};

string mul2 (string& s) {
    string out;
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int res = (s[i]  - '0') * 2 + carry;
        out += res % 10 + '0';
        carry = res / 10;
    }
    if (carry) {
        out += carry + '0';
    }
    reverse(out.begin(), out.end());
    return out;
}

void buildTrie(Trie &trie, int n) {
    string s = "1";
    trie.insert(s);
    for (int i = 0; i < n; i++) {
        s = mul2(s);
        trie.insert(s);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Trie trie;
    buildTrie(trie, 800);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += trie.count(s, i);
        }
        cout << cnt << endl;
    }
    return 0;
}
