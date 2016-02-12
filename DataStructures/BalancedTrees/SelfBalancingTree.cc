/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node *n) {
    return n ? n->ht : -1;
}

int balance_factor(node *n) {
    return height(n->left) - height(n->right);
}

node* Lrotate(node *n) {
    node *root = n->right;
    node *temp = root->left;
    root->left = n;
    n->right = temp;
    n->ht = max(height(n->left), height(n->right)) + 1;
    root->ht = max(height(root->left), height(root->right)) + 1;
    return root;
}

node* Rrotate(node *n) {
    node *root = n->left;
    node *temp = root->right;
    root->right = n;
    n->left = temp;
    n->ht = max(height(n->left), height(n->right)) + 1;
    root->ht = max(height(root->left), height(root->right)) + 1;
    return root;
}

node * insert(node * root,int val)
{
    if (!root) {
        return new node{val, nullptr, nullptr, 0};
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    root->ht = max(height(root->left), height(root->right)) + 1;

    int bf = balance_factor(root);
    if (bf == 2 && balance_factor(root->left) == 1) {
        return Rrotate(root);
    }

    if (bf == 2 && balance_factor(root->left) == -1) {
        root->left = Lrotate(root->left);
        return Rrotate(root);
    }

    if (bf == -2 && balance_factor(root->right) == -1) {
        return Lrotate(root);
    }

    if (bf == -2 && balance_factor(root->right) == 1) {
        root->right = Rrotate(root->right);
        return Lrotate(root);
    }
    return root;
}
