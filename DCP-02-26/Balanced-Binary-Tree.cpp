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
14int solve(TreeNode *node){
15    if(!node)return 0;
16
17    int l=solve(node->left);
18    if(l==-1)return -1;
19    int r=solve(node->right);
20    if(r==-1)return -1;
21
22    if(abs(l-r)>1)return -1;
23
24    return 1+max(l,r);
25}
26    bool isBalanced(TreeNode* root) {
27        return solve(root)!=-1;
28    }
29};