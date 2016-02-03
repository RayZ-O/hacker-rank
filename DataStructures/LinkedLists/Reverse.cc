/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* reverse(Node *node, Node* prev) {
    if (!node) {
        return nullptr;
    }
    Node* next = node->next;
    node->next = prev;
    return next ? reverse(next, node) : node;
}

Node* Reverse(Node *head)
{
    return reverse(head, nullptr);
}
