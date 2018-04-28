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
    pair<ListNode*, bool> the_sum(ListNode* l1, ListNode* l2, int len1, int len2) {
        ListNode* node = new ListNode(0);
        bool rem = 0;
        if (!l1->next && !l2->next) {
            //cout << l1->val << " " << l2->val << endl;
            node->val = l1->val + l2->val;
            if (node->val > 9) {
                node->val -= 10;
                rem = 1;
            }
            return make_pair(node, rem);
        }
        pair<ListNode*, bool> p;
        //cout << len1 << " " << len2 << endl;
        if (len1 > len2 + 1) {
            p = the_sum(l1->next, l2, len1 - 1, len2);
            node->next = p.first;
        }
        else if (len1 == len2 + 1) {
            p = the_sum(l1->next, l2->next, len1 - 1, len2 - 1);
            node->next = p.first;
        }
        node->val = l1->val + l2->val + p.second;
        if (node->val > 9) {
            node->val -= 10;
            rem = 1;
        }
        return make_pair(node, rem);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return 0;
        }
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int len1 = 0;
        int len2 = 0;
        while (temp1) {
            ++len1;
            temp1 = temp1->next;
        }
        while (temp2) {
            ++len2;
            temp2 = temp2->next;
        }
        pair <ListNode*, int> ans;
        ListNode* zero = new ListNode(0);
        if (len1 == len2) {
            ans = the_sum(l1, l2, len1, len2 - 1);
        }
        else { 
            if (len2 > len1) {
                swap(len2, len1);
                swap(l1, l2);
            }
            zero->next = l2;
            zero->val = 0;
            ans = the_sum(l1, zero, len1, len2);
        }
        if (ans.second) {
            zero->next = ans.first;
            zero->val = 1;
            return zero;
        }
        return ans.first;
    }
};