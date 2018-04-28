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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> q;
        vector<int> d;
        vector<vector<int>> v;
        if (!root) return v;
        int h=-1,t=0;
        q.push_back(root);
        d.push_back(0);
        while (h<t) {
            h++;
            if (!d[h] || d[h]!=d[h-1]) v.push_back(vector<int>());
            v[d[h]].push_back(q[h]->val);
            if (q[h]->left) {
                t++;
                d.push_back(d[h]+1);
                q.push_back(q[h]->left);
            }
            if (q[h]->right) {
                t++;
                d.push_back(d[h]+1);
                q.push_back(q[h]->right);
            }
        }
        return v;
    }
};