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
12class Solution {
13public:
14    void flatten(TreeNode* root) {
15        TreeNode *prev=root;
16        TreeNode*curr=root;
17        while(curr){
18            if(curr->left){
19               prev=curr->left;
20               while(prev->right){
21                  prev=prev->right;
22               }
23
24               prev->right=curr->right;
25               curr->right=curr->left;
26               curr->left=NULL;
27            }
28            curr=curr->right;
29        }
30    }
31};