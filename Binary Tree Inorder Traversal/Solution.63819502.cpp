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
    void aux(TreeNode* v, vector<int> &nodes) {
        if (!v) return;
        aux(v->left,nodes);
        nodes.push_back(v->val);
        aux(v->right,nodes);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        aux(root,nodes);
        return nodes;
    }
};