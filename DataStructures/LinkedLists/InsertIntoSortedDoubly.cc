/*
    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    if (!head) {
        head = new Node{data, nullptr, nullptr};
    } else if (data < head->data) {
        Node *n = new Node{data, head, head->prev};
        if (head->prev)
            head->prev->next = n;
        head->prev = n;
        head = n;
    } else {
        head->next = SortedInsert(head->next, data);
    }
    return head;
}
