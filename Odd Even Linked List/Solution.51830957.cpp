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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* temp=head->next;
        ListNode* p2=head->next;
        ListNode* p1=head;
        while(p1->next && p1->next->next) {
            p1->next=p1->next->next;
            p1=p1->next;
            if (p2->next) {
                p2->next=p2->next->next;
                p2=p2->next;
            }    
        }
        p1->next=temp;
        return head;
    }
};