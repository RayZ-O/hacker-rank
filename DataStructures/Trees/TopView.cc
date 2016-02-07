/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
#include <list>

void top_view(node * root)
{
    list<int> li;
    if (root) {
        node *n = root;
        while (n->left) {
            li.push_front(n->left->data);
            n = n->left;
        }
        li.push_back(root->data);
        n = root;
        while (n->right) {
            li.push_back(n->right->data);
            n = n->right;
        }
        for (int i : li) {
            cout << i << " ";
        }
    }
}
