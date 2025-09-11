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
int n;
TreeNode* solve(vector<int>& p,int &i,int bound){
  if(i==p.size()||p[i]>bound){
    return NULL;
  }
TreeNode*root=new TreeNode(p[i++]);
root->left=solve(p,i,root->val);
root->right=solve(p,i,bound);
return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);

    }
};