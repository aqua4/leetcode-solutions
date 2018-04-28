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
    // pair<depth, value>
    pair<int, int> find_bottom_left_value(TreeNode* root, int depth) {
        pair<int, int> p = make_pair(depth, root->val);
        if (root->right) {
            p = find_bottom_left_value(root->right, depth + 1);
        }
        if (root->left) {
            pair<int, int> left = find_bottom_left_value(root->left, depth + 1);
            if (left.first >= p.first) {
                p = left;
            }
        }
        return p;
    }

    int findBottomLeftValue(TreeNode* root) {
        return find_bottom_left_value(root, 0).second;
    }
};