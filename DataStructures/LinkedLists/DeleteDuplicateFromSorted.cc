/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    Node* cur = head;
    while (cur) {
        Node *n = cur->next;
        while (n && n->data == cur->data) {
            Node *t = n->next;
            delete n;
            n = t;
        }
        cur->next = n;
        cur = n;
    }
    return head;
}
