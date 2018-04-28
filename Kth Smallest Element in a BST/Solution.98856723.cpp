/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int ans;
public:
    bool trav(TreeNode* n, int& k, int& cur) {
        if (n->left && trav(n->left, k, cur)) {
            return 1;
        }
        ++cur;
        if (cur == k) {
            ans = n->val;
            return 1;
        }
        if (n->right && trav(n->right, k, cur)) {
            return 1;
        }
        return 0;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        trav(root, k, cur);
        return ans;
    }
};