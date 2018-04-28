/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void conn(TreeLinkNode *n, TreeLinkNode *p) {
        if (!n) return;
        if (p) {
            TreeLinkNode* p2 = p;
            if (p->right && p->right != n) n->next = p->right;
            else while (p2->next) {
                //cout<<p->val<<" ";
                if (p2->next->left) {
                    n->next = p2->next->left;
                    break;
                } else
                if (p2->next->right) {
                    n->next = p2->next->right;
                    break;
                }
                p2 = p2->next;
            }
            //cout<<endl;
        }   
        if (n->next) {
            while (p->left != n->next && p->right != n->next) p = p->next;
            conn(n->next, p);
        }    
        if (n->left && !n->left->next) conn(n->left,n);
        if (n->right && !n->right->next) conn(n->right,n);
    }

    void connect(TreeLinkNode *root) {
        conn(root,0);
    }
};