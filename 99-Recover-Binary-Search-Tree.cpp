
class Solution {
public:
    TreeNode *prev;
    TreeNode *first;
    TreeNode *second;

    void inorder(TreeNode *root){
        if(!root)return ;
       
        inorder(root->left);
        if(prev->val>root->val){
            if(!first){
                first=prev;
            }

            second=root;
        }
        prev=root;
        inorder(root->right);
        
    }

    void recoverTree(TreeNode* root) {
        if(!root)return;
        prev=new TreeNode(INT_MIN);
        first=NULL;
        second=NULL;
        inorder(root);
      
        swap(first->val,second->val);




    }
};