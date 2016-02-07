/*
Node is defined as

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Preorder(node *root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
