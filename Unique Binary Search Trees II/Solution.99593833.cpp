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
    vector<TreeNode*> generate(int mini, int maxi) {
        if (mini > maxi) {
            return {};
        }
        vector<TreeNode*> cur;
        if (mini == maxi) {
            cur.push_back(new TreeNode(mini));
            return cur;
        }
        for (int i = mini; i <= maxi; ++i) {
            vector<TreeNode*> left = generate(mini, i - 1);
            vector<TreeNode*> right = generate(i + 1, maxi);
            if (left.empty()) {
                for (const auto& r : right) {
                    cur.push_back(new TreeNode(i));
                    cur.back()->right = r;
                }
                continue;
            }
            if (right.empty()) {
                for (const auto& l : left) {
                    cur.push_back(new TreeNode(i));
                    cur.back()->left = l;
                }
                continue;
            }
            for (const auto& l : left) {
                for (const auto& r : right) {
                    cur.push_back(new TreeNode(i));
                    cur.back()->left = l;
                    cur.back()->right = r;
                }
            }
        }
        return cur;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};