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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    if (head == NULL or head->next == NULL) return head;
    LinkedListNode<int>*rev_head = reverseLinkedList(head->next);
    LinkedListNode<int> * rev_tail = head->next;
    if (rev_head == NULL) {
        return head;
    }
    rev_tail->next = head;
    head->next = NULL;
    return rev_head;

}