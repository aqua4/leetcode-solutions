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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       int h=-1,t=0,c=-1;
       vector<TreeNode*> q;
       vector<vector<int>> v;
       if (!root) return v;
       vector<int> d;
       q.push_back(root);
       d.push_back(0);
       while(h<t) {
           h++;
           //if (layer[cur]>=v.size()) v.resize(layer[cur]+1);
           if (c!=d[h]) {
               c=d[h];
               v.push_back(vector<int>());
           }
           v[d[h]].push_back(q[h]->val);
           //cout<<cur->val;
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
       reverse(v.begin(),v.end());
       return v;
    }
};