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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return 0;
        int t = rem(head,NULL,n,0);
        if (t>-10) head=head->next;
        return head;
    }
    int rem(ListNode* head, ListNode* p, int n, int i) {
        if (!head) return i;
        int sz = rem(head->next,head,n,i+1);
        if (sz-i == n+1) {
            head->next = head->next->next;
            return -10;
        } 
        return sz;
    }
};