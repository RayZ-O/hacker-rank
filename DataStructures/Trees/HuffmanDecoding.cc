/*
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;

}node;

*/

void decode_huff(node * root,string s)
{
    string res;
    node *n = root;
    for (char c : s) {
        if (c == '0') {
            n = n->left;
        } else {
            n = n->right;
        }
        if (n->data != '\0') {
            res += n->data;
            n = root;
        }
    }
    cout << res << endl;
}
