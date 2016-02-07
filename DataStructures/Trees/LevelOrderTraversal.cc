/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
#include <queue>

void LevelOrder(node * root)
{
    if (!root) {
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            node* t = q.front();
            q.pop();
            cout << t->data << " ";
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }
}
