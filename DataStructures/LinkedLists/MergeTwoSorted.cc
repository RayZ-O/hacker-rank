/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    if (!headA) {
        return headB;
    }
    if (!headB) {
        return headA;
    }
    if (headA->data < headB->data) {
        Node *next = headA->next;
        headA->next = MergeLists(next, headB);
        return headA;
    } else {
        Node *next = headB->next;
        headB->next = MergeLists(headA, next);
        return headB;
    }
}
