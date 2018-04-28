/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand (time(NULL));
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = this->head;
        ListNode* node = this->head;
        cur = cur->next;
        int i = 2;
        while (cur) {
            int r = rand() % i;
            //cout << r;
            if (r == 0) {
                node = cur;
            }
            ++i;
            cur = cur->next;
        }
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */