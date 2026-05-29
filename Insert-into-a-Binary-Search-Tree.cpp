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
14    TreeNode* insertIntoBST(TreeNode* root, int val) {
15        if(!root){
16            return new TreeNode(val);
17        }
18
19        TreeNode* temp=root;
20        while(temp){
21            if(val>temp->val){
22                if(temp->right){
23                    temp=temp->right;
24                }else{
25                    temp->right=new TreeNode(val);
26                    break; 
27                }
28            }else{
29                 if(temp->left){
30                    temp=temp->left;
31                }else{
32                    temp->left=new TreeNode(val);
33                    break; 
34                }
35            }
36        }
37        return root;
38    }
39};