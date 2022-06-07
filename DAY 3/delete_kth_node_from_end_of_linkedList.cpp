#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if (head == NULL or K == 0) return head;
    LinkedListNode<int> * slow = head, *fast = head;
    while (K--) {
        fast = fast->next;
    }
    if (fast == NULL) {
        fast = slow->next;
        return fast;
    }
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    fast = slow->next;
    slow->next = fast->next;
    delete(fast);
    return head;
}