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
    bool ispal(ListNode* head, ListNode* &p1) {
        if (!head) return 1;
        bool b = ispal(head->next,p1);
        if (!b || p1->val != head->val) return 0;
        p1 = p1->next;
        return 1;
    }
    
    bool isPalindrome(ListNode* head) {
        return ispal(head,head);
    }
};