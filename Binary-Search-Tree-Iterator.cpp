1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class BSTIterator {
13public:
14     stack<TreeNode*>s;
15
16    void pushAll(TreeNode*temp){
17        while(temp){
18            s.push(temp);
19            temp=temp->left;
20        }
21    }
22    BSTIterator(TreeNode* root) {
23        pushAll(root);
24    }
25    
26    int next() {
27        TreeNode* nextele=s.top();
28        s.pop();
29        pushAll(nextele->right);
30        return nextele->val;
31    }
32    
33    bool hasNext() {
34        return !s.empty();
35    }
36};
37
38/**
39 * Your BSTIterator object will be instantiated and called as such:
40 * BSTIterator* obj = new BSTIterator(root);
41 * int param_1 = obj->next();
42 * bool param_2 = obj->hasNext();
43 */