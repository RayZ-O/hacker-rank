#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void swapOp(TreeNode *root, int k, int depth) {
    if (!root) {
        return;
    }
    if (depth % k == 0) {
        swap(root->left, root->right);
    }
    swapOp(root->left, k, depth + 1);
    swapOp(root->right, k, depth + 1);
}

void inorder(TreeNode *root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<TreeNode> nodes(n, TreeNode(0));
    for (int i = 0; i < n; i++) {
        nodes[i].data = i + 1;
        int a, b;
        cin >> a >> b;
        if (a != -1) {
            nodes[i].left = &nodes[a-1];
        }
        if (b != -1) {
            nodes[i].right = &nodes[b-1];
        }
    }
    TreeNode *root = &nodes[0];
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        swapOp(root, k, 1);
        inorder(root);
        cout << endl;
    }
    return 0;
}
