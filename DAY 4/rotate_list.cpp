#include <bits/stdc++.h>
/********************************

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

********************************/
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + n - (k % n));
    reverse(nums.begin() + n - (k % n), nums.end());
    reverse(nums.begin(), nums.end());
}

Node *rotate(Node *head, int k) {
    // Write your code here.
    if (head == NULL) return NULL;
    if (k == 0) return head;
    vector<int> nodes;
    Node * curr = head;
    while (curr != NULL) {
        nodes.push_back(curr->data);
        curr = curr->next;
    }

    rotateArray(nodes, k);

    curr = head;
    for (int i = 0; i < nodes.size(); i++) {
        curr->data = nodes[i];
        curr = curr->next;
    }

    nodes.clear();
    return head;
}

