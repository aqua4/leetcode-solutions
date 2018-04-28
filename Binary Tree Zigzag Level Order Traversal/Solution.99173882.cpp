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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        bool rev = 0;
        vector<vector<int> > ans;
        vector<int> v;
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int dist = q.front().second;
            v.push_back(cur->val);
            q.pop();
            if (cur->left) {
                q.push(make_pair(cur->left, dist + 1));
            }
            if (cur->right) {
                q.push(make_pair(cur->right, dist + 1));
            }
            if (q.empty() || dist != q.front().second) {
                if (rev) {
                    reverse(v.begin(), v.end());
                }
                ans.push_back(v);
                v.clear();
                rev = !rev;
            }
        }
        return ans;
    }
};