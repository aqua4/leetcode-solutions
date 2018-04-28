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
        nodes.push_back(v->val);
        aux(v->left,nodes);
        aux(v->right,nodes);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        aux(root,nodes);
        return nodes;
    }
};