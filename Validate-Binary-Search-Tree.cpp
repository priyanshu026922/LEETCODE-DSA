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

bool valid(TreeNode*root,long maxi,long mini){
    if(!root)return true;
    if(root->val>mini&&maxi>root->val){
       bool  l=valid(root->left,root->val,mini);
       bool  r=valid(root->right,maxi,root->val);
         return l&&r;
    }
    return false;
}
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MAX,LONG_MIN);
    }
};