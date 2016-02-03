/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node n{0, head};
    Node* cur = &n;
    while (position--) {
        cur = cur->next;
    }
    cur->next = new Node{data, cur->next};
    return n.next;
}
