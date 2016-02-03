/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *r1 = headA, *r2 = headB;
    while (r1 || r2) {
        if (!r1) {
            r1 = headA;
        }
        if (!r2) {
            r2 = headB;
        }
        if (r1 == r2) {
            return r1->data;
        }
        r1 = r1->next;
        r2 = r2->next;
    }
    return -1;
}
