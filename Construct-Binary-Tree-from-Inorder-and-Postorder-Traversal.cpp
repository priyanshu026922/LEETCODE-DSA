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
14    int n;
15    unordered_map<int,int>mp;
16    TreeNode* solve(int inS,int inE,vector<int>&in,int poS,int poE,vector<int>&pos){
17        if(inS>inE||poS>poE){
18            return NULL;
19        }
20
21        TreeNode*node= new TreeNode(pos[poE]);
22        int l=mp[node->val];
23        int numbers_left=mp[node->val]-inS;
24        node->left=solve(inS,l-1,in,poS,numbers_left+poS-1,pos);
25        node->right=solve(l+1,inE,in, numbers_left+poS,poE-1,pos);
26        
27        return node;
28    }
29
30    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
31        n=inorder.size();
32    
33        for(int i=0;i<n;i++){
34            mp[inorder[i]]=i;
35        }
36        return solve(0,n-1, inorder,0,n-1,postorder);
37    }
38};