/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    Node n{0, head};
    Node *cur = &n;
    while (position--) {
        cur = cur->next;
    }
    Node *t = cur->next;
    cur->next = cur->next->next;
    delete t;
    return n.next;
  // Complete this method
}
