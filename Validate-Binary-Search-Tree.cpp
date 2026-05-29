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
14    bool solve(TreeNode *node,long long mini,long long  maxi){
15        if(!node){
16            return true;
17        }
18
19        if(node->val>mini && maxi>node->val){
20            bool l=solve(node->left,mini,node->val);
21            bool r=solve(node->right,node->val,maxi);
22            return l&&r;
23        }
24        return false;
25    }
26    bool isValidBST(TreeNode* root) {
27        if(!root){
28            return true;
29        }
30
31        return solve(root,LLONG_MIN,LLONG_MAX);
32    }
33};