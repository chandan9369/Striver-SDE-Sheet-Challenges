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

int findIntersection(Node* head1, Node *head2)
{
    int c1 = 0;
    int c2 = 0;
    Node *curr1 = head1;
    Node *curr2 = head2;
    while (curr1 != NULL)
    {
        curr1 = curr1->next;
        c1++;
    }
    while (curr2 != NULL)
    {
        curr2 = curr2->next;
        c2++;
    }
    int v = abs(c1 - c2);
    Node *temp1 = (c1 > c2) ? head1 : head2;
    Node *temp2 = (c1 > c2) ? head2 : head1;

    for (int i = 1; i <= v; i++)
    {
        temp1 = temp1->next;
    }
    while (temp1 != NULL and temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}