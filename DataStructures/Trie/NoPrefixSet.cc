#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    bool is_end;
    int num_branch;
    Node* children[26];
    Node() : is_end(false), num_branch(0) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    Node *root;
public:
    Trie() : root(new Node) {}

    bool add(string s) {
        Node *node = root;
        for (char c : s) {
            if (node->is_end) {
                return false;
            }
            if (!node->children[c-'a']) {
                node->num_branch++;
                node->children[c-'a'] = new Node;
            }
            node = node->children[c-'a'];
        }
        if (node->num_branch > 0 || node->is_end) {
            return false;
        }
        node->is_end = true;
        return true;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    Trie trie;
    while (n--) {
        string s;
        cin >> s;
        if (!trie.add(s)) {
            cout << "BAD SET\n" << s << endl;
            return 0;
        }
    }
    cout << "GOOD SET" << endl;
    return 0;
}
