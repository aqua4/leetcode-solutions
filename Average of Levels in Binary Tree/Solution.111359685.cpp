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
    void average_of_levels(TreeNode* root, int level, vector<double>& sum, vector<int>& count) {
        if (!root) {
            return;
        }
        if (sum.size() == level) {
            sum.push_back(root->val);
            count.push_back(1);
        }
        else {
            sum[level] += root->val;
            ++count[level];
        }
        average_of_levels(root->left, level + 1, sum, count);
        average_of_levels(root->right, level + 1, sum, count);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> count;
        average_of_levels(root, 0, sum, count);
        for (int i = 0; i < sum.size(); ++i) {
            sum[i] /= count[i];
        }
        return sum;
    }
};