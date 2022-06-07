#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/
void assign(Node* &head, Node* &tail, Node* ptr) {
    if (ptr == NULL)
        return;
    if (head == NULL) {
        head = ptr;
        tail = ptr;
    }
    else {
        tail -> child = ptr;
        tail = tail -> child;
    }
}
Node* mergeList(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1 -> data <= head2 -> data) {
            assign(head, tail, head1);
            head1 = head1 -> child;
        }
        else {
            assign(head, tail, head2);
            head2 = head2 -> child;
        }
    }
    if (head1 == NULL) assign(head, tail, head2);
    if (head2 == NULL) assign(head, tail, head1);
    return head;

}

Node* flattenLinkedList(Node* root)
{
    // Write your code here
    // Your code here
    Node* head = NULL;
    Node* ptr = root;
    Node* next = NULL;
    while (ptr != NULL) {
        next = ptr -> next;
        ptr -> next = NULL;
        head = mergeList(head, ptr);
        ptr = next;
    }
    return head;
}
