/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head) {
        return head ? (1 + len(head->next)) : 0;
    }

    ListNode* F(ListNode* head, int count, int k) {

        if (count == 0) return head;

        ListNode* prev = NULL, *cur = head, *next = NULL;
        for (int i = 0; i < k; i++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = F(cur, count - 1, k);

        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int itr = len(head) / k;
        return F(head, itr, k);

    }
};