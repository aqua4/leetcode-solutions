/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        ListNode* n = head->next->next;
        ListNode* first = head->next;
        head->next->next = head;
        head->next=swapPairs(n);
        return first;
    }
};