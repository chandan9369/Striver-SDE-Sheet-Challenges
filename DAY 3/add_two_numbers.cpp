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

Node *addTwoNumbers(Node *l1, Node *l2, int carry = 0)
{
    if (!l1 and !l2)
    {
        if (carry > 0)
        {
            return new Node(carry);
        }
        return nullptr;
    }
    int op1 = l1 ? l1->data : 0;
    int op2 = l2 ? l2->data : 0;
    int sum = op1 + op2 + carry;
    Node *res = new Node(sum % 10);
    res->next = addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum         / 10);
    return res;
}