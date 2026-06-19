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
14  //{T,NT}:::
15    pair<int,int> solve(TreeNode*temp){
16       if(!temp){
17        return {0,0};
18       }
19
20       if(!temp->left&&!temp->right){
21        return {temp->val,0};
22       }
23
24       pair<int,int>p1=solve(temp->left);
25       pair<int,int>p2=solve(temp->right);
26
27       int t=temp->val+p1.second+p2.second;
28       int nt=p1.first+p2.first;
29       int t2=p2.second+p1.second;
30       int maxi=max({t,nt,t2});
31       return {maxi,nt};
32
33    }
34    int rob(TreeNode* root) {
35        
36      pair<int,int>val=solve(root);
37      return max(val.first,val.second);
38    }
39};