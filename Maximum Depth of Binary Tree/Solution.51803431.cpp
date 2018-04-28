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
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int maxi=0;
        if (root->left!=NULL) maxi=maxDepth(root->left);
        if (root->right!=NULL) maxi=max(maxi,maxDepth(root->right));
        return maxi+1;
    }
};