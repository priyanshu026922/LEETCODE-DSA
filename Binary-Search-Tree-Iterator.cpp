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
class BSTIterator {
private:
   void pushall(TreeNode*node){
         TreeNode*n=node;
         while(n){
            s.push(n);
            n=n->left;
         }
   }
public:
stack<TreeNode*>s;

    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode*nextele=s.top();
        s.pop();
        pushall(nextele->right);
         return nextele->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */