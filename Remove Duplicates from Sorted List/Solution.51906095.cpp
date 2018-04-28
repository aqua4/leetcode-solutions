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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start=head;
        while (head && head->next) {
            while (head->next && head->next->val==head->val) {
                head->next=head->next->next;
            }
            head=head->next;
        }    
        return start;
    }
};