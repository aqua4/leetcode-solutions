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
    void dfs(TreeNode* root, string s, vector<string> &str) {
        if (!root->left && !root->right) str.push_back(s);
        if (root->left) dfs(root->left,s+"->"+to_string(root->left->val),str);
        if (root->right) dfs(root->right,s+"->"+to_string(root->right->val),str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> str;
        if (!root) return str;
        dfs(root,to_string(root->val),str);
        return str;
    }
};