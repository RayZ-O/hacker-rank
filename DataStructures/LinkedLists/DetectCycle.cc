/*
  Detect loop in a linked list
  List could be empty also
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
    Node *fast = head, *slow = head;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
        if (fast) {
            fast = fast->next;
        }
        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}
