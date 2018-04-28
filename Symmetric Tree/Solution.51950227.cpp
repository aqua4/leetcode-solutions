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
public:
    bool dfs(TreeNode* l1,TreeNode* l2) {
        if (!l1 && !l2) return 1;
        if (!l1 || !l2) return 0;
        if (l1->val!=l2->val) return 0;
        return dfs(l1->left,l2->right) && dfs(l1->right,l2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return 1;
        return dfs(root->left,root->right);
    }
};