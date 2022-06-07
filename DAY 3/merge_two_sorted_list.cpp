#include <bits/stdc++.h>
/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* a, Node<int>* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node<int>*tail = NULL, *head = NULL;
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    Node<int>*c1 = a, *c2 = b;
    while (c1 != NULL and c2 != NULL)
    {
        if (c1->data <= c2->data)
        {
            tail->next = c1;
            tail = c1;
            c1 = c1->next;
        }
        else
        {
            tail->next = c2;
            tail = c2;
            c2 = c2->next;
        }
    }
    if (c1 == NULL)
    {
        tail->next = c2;
    }
    else
    {
        tail->next = c1;
    }
    return head;
}
