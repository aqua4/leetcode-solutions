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
    bool hasPathSum(TreeNode* root, int sum) {
        if (sum!=0 && !root) return 0;
        static bool b=0;
        if (sum==0 && !root) {
            if (b) return 1;
            return 0;
        }
        b=1;
        bool b1=hasPathSum(root->left,sum-root->val);
        bool b2=hasPathSum(root->right,sum-root->val);
        cout<<root->val<<" "<<b1<<" "<<b2<<" "<<endl;
        return (root->left && b1) || (root->right && b2) || (b1 && b2);
    }
};