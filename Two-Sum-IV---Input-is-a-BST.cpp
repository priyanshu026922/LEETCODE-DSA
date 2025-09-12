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
 class BST{
    stack<TreeNode*>s;
    bool rev=true;
    private:
    void pushall(TreeNode*root){
        TreeNode*node=root;
        while(node){
             s.push(node);
            if(rev){
                node=node->right;
            }else{
               node=node->left;
            }
        }
    }
    public:
      BST(TreeNode*root,bool rev){
           this->rev=rev;
         pushall(root);
      
      }
      
      int next(){
          TreeNode*node=s.top();
          s.pop();
          if(!rev){
             pushall(node->right);
          }else{
            pushall(node->left);
          }
          return node->val;
      }
    
 };





class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
    if(!root)return false;
    BST l(root,false);
    BST r(root,true);
    int i=l.next();
    int j=r.next();
    while(i<j){
        if(i+j==k)return true;
        else if(i+j<k)i=l.next();
        else j=r.next();
    }
    return false;
    }
};
