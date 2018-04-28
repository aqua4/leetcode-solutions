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
    int summation(TreeNode* root, unordered_map<int, int> &hash) {
        if (!root) {
            return 0;
        }
        int sum = summation(root->left, hash) + summation(root->right, hash) + root->val;
        ++hash[sum];
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> hash;
        summation(root, hash);
        int ma = 0;
        for (auto rec : hash) {
            ma = max(rec.second, ma);
        }
        vector<int> ans;
        for (auto rec : hash) {
            if (rec.second == ma) {
                ans.push_back(rec.first);
            }
        }
        return ans;
    }
};