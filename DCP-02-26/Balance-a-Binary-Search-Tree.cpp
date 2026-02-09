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
14TreeNode * BST(vector<int>&vec,int s,int e){
15    if(s>e){
16        return NULL;
17    }
18
19    int mid=(s+e)/2;
20    TreeNode * root=new TreeNode(vec[mid]);
21    root->left=BST(vec,s,mid-1);
22    root->right=BST(vec,mid+1,e);
23    return root;
24}
25    void solve(TreeNode *root,vector<int>&ans){
26        if(!root){
27            return;
28        }
29        solve(root->left,ans);
30        ans.push_back(root->val);
31        solve(root->right,ans);
32    }
33    TreeNode* balanceBST(TreeNode* root) {
34        vector<int>vec;
35        solve(root,vec);
36        int n=vec.size();
37        return BST(vec,0,n-1);
38
39
40    }
41};