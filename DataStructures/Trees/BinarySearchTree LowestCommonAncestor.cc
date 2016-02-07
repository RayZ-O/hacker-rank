/*
Node is defined as

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * lca(node * root, int v1,int v2)
{
    if (!root) {
        return nullptr;
    }
    if (v1 > v2) {
        swap(v1, v2);
    }
    if (root->data < v1) {
        return lca(root->right, v1, v2);
    } else if (root->data > v2) {
        return lca(root->left, v1, v2);
    } else {
        return root;
    }
}

