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
    void largest_values(TreeNode* root, int depth, vector<int> &v) {
        if (!root) {
            return;
        }
        if (depth >= v.size()) {
            v.push_back(root->val);
        }
        largest_values(root->left, depth + 1, v);
        largest_values(root->right, depth + 1, v);
        v[depth] = max(v[depth], root->val);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        largest_values(root, 0, ans);
        return ans;
    }
};