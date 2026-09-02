/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode *l,TreeNode *r){
        if(!l&&r)return false;
        if(!l&&!r)return true;
        if(l&&!r)return false;

        bool le=solve(l->right,r->left);
        bool re=solve(l->left,r->right);
        if(le&&re&&l->val==r->val){
            return true;
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }

        if(!root->left&&!root->right){
            return true;
        }

        return solve(root->left,root->right);
    }
};