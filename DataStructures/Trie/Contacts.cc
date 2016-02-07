#include <iostream>
using namespace std;

struct Node {
    int count;
    Node* children[26];
    Node() : count(0) {}
};

class Trie {
    Node *root;
public:
    Trie() : root(new Node) {}

    void add(string name) {
        Node *node = root;
        for (char c : name) {
            if (!node->children[c-'a']) {
                node->children[c-'a'] = new Node;
            }
            node = node->children[c-'a'];
            node->count++;
        }
    }

    int find(string name) {
        int count = 0;
        Node *node = root;
        for (char c : name) {
            if (!node->children[c-'a']) {
                return 0;
            }
            node = node->children[c-'a'];
        }
        return node->count;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    Trie trie;
    while (n--) {
        string a, b;
        cin >> a >> b;
        if (a == "add") {
            trie.add(b);
        } else {
            cout << trie.find(b) << endl;
        }
    }
    return 0;
}
