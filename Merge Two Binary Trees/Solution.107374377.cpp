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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return 0;
        }
        int val = 0;
        TreeNode* left1 = 0;
        TreeNode* left2 = 0;
        TreeNode* right1 = 0;
        TreeNode* right2 = 0;
        if (t1) {
            left1 = t1->left;
            right1 = t1->right;
            val += t1->val;
        }
        if (t2) {
            left2 = t2->left;
            right2 = t2->right;
            val += t2->val;
        }
        TreeNode* node = new TreeNode(val);
        node->left = mergeTrees(left1, left2);
        node->right = mergeTrees(right1, right2);
        return node;
    }
};