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
    void trav(TreeNode* n, vector<int>& v) {
        if (!n) return;
        trav(n->left,v);
        trav(n->right,v);
        v.push_back(n->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        trav(root,v);
        return v;
    }
};