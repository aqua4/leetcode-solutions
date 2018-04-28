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
    TreeNode* dfs(int l, int r, int& cur, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& index) {
        int ind = index[preorder[cur]];
        if (l > r || ind > r || ind < l) {
            return 0;
        }
        if (l == r) {
            ++cur;
            return new TreeNode(inorder[l]);
        }
        TreeNode* node = new TreeNode(preorder[cur]);
        ++cur;
        node->left = dfs(l, ind - 1, cur, preorder, inorder, index);
        node->right = dfs(ind + 1, r, cur, preorder, inorder, index);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (!n) {
            return 0;
        }
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        int cur = 0;
        return dfs(0, n - 1, cur, preorder, inorder, index);
    }
};