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
    TreeNode* BST(vector<int>& nums, int l, int r) {
        int mid = (l + r) / 2;
        if (mid < 0 || mid >= nums.size() || l > r) {
            return 0;
        }
        TreeNode* node = new TreeNode(nums[mid]);
        if (l == r) {
            return node;
        }
        node->left = BST(nums, l, mid - 1);
        node->right = BST(nums, mid + 1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        return BST(nums, 0, n - 1);
    }
};