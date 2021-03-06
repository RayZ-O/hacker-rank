/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    if (!head) {
        head = new Node;
        head->data = data;
    } else {
        Node *cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new Node;
        cur->next->data = data;
    }
    return head;
  // Complete this method
}
