#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *slow = head, *fast = head;
    // flyod's algorithm to detect cycle in a linked list
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    // checking whether cycle exist or not
    if (slow != fast)
    {
        return NULL;
    }
    slow = head;
    // loop for getting starting node of cycle
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}