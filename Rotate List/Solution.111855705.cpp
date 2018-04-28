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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return 0;
        if (k == 0) return head;
        int n = 0;
        for (ListNode* l = head; l != 0; l = l->next) ++n;
        k %= n;
        if (k == 0) return head;
        ListNode* newhead = 0;
        int c = 0;
        ListNode* i;
        k = n - k;
        for (i = head; i->next != 0;) {
            ++c;
            if (c == k) {
                newhead = i->next;
                i->next = 0;
                i = newhead;
                continue;
            }
            i = i->next;
        }
        i->next = head;
        return newhead;
    }
};