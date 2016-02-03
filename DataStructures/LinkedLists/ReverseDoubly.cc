/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

Node* Reverse(Node* head)
{
    if (!head) {
        return nullptr;
    }
    Node *next = head->next;
    head->next = head->prev;
    head->prev = next;
    return next ? Reverse(next) : head;
}
