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
       queue<TreeNode*> q;
       vector<vector<int>> v;
       if (!root) return v;
       map<TreeNode*,int> layer;
       layer[root]=0;
       q.push(root);
       while(!q.empty()) {
           TreeNode* cur=q.front();
           q.pop();
           if (layer[cur]>=v.size()) v.resize(layer[cur]+1);
           v[layer[cur]].push_back(cur->val);
           cout<<cur->val;
           if (cur->left) {
               layer[cur->left]=layer[cur]+1;
               q.push(cur->left);
           }
           if (cur->right) {
               layer[cur->right]=layer[cur]+1;
               q.push(cur->right);
           }
       }
       reverse(v.begin(),v.end());
       return v;
    }
};