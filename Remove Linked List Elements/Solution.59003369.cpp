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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return 0;
        while(head && head->val==val) head=head->next;
        ListNode* tmp=head;
        ListNode* first=head;
        if (head) head=head->next;
        while(head) {
            if (head->val==val) {
                tmp->next=head->next;
            } else
            tmp=head;
            head=head->next;
        }
        return first;
    }
};