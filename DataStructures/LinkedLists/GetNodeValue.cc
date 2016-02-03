/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    Node *fast = head, *slow = head;
    while (fast) {
        fast = fast->next;
        if (positionFromTail < 0) {
            slow = slow->next;
        }
        positionFromTail--;
    }
    return slow->data;
}
