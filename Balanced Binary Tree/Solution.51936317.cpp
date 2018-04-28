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
    int dfs(TreeNode* root) {
        int l=0;
        if (root->left) l=dfs(root->left);
        int r=0;
        if (root->right) r=dfs(root->right);
        if (r==-1 || l==-1) return -1;
        if (abs(r-l)>1) return -1;
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return 1;
        return dfs(root)!=-1;
    }
};