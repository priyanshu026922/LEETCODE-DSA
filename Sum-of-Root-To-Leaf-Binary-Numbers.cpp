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
14int sum=0;
15int getSum(string s){
16    int t=0;
17    reverse(begin(s),end(s));
18    int j=0;
19    for(int i=0;i<s.length();i++){
20        if(s[i]=='1'){
21            t+=(1<<j);
22        }
23        j++;
24    }
25    return t;
26}
27    void solve(TreeNode*root,string x){
28        if(!root){
29            return;
30        }
31       
32        int val=root->val;
33        x+=to_string(val);
34        solve(root->left,x);
35        solve(root->right,x);
36        if(!root->left&&!root->right){
37           sum+=getSum(x);
38        }
39        x.pop_back(); 
40    }
41    int sumRootToLeaf(TreeNode* root) {
42         solve(root,"");
43         return sum;
44    }
45};