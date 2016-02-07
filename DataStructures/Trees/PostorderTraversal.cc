/*
Node is defined as

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void Postorder(node *root) {
    if (!root) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
