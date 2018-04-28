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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* hnext;
        ListNode* hprev=head;
        head=head->next;
        hprev->next=0;
        while(head) {
            hnext=head->next;
            head->next=hprev;
            hprev=head;
            head=hnext;
        }
        return hprev;
    }
};