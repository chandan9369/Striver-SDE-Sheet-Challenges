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
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    while (curr != NULL)
    {
        LinkedListNode<int> *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if (head == NULL) return true;
    LinkedListNode<int> * slow = head, *fast = head;
    // find middle node
    while (fast->next != NULL and fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode<int> * rev_list = reverse(slow->next);
    LinkedListNode<int> * temp = head;
    while (rev_list != NULL) {
        if (rev_list->data != temp->data) {
            return false;
        }
        rev_list = rev_list->next;
        temp = temp->next;
    }
    return true;

}