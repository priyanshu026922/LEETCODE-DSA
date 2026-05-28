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
14    TreeNode* searchBST(TreeNode* root, int val) {
15        TreeNode*temp=root;
16        while(temp){
17            if(temp->val==val){
18                return temp;
19            }
20            if(temp->val<val){
21                temp=temp->right;
22            }
23            else{
24               temp= temp->left;
25            }
26        }
27        return NULL;
28    }
29};