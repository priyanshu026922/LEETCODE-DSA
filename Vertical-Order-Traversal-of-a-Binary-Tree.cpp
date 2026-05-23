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
14    vector<vector<int>> verticalTraversal(TreeNode* root) {
15        vector<vector<int>>ans;
16        map<int,map<int,multiset<int>>>mp;
17        queue<pair<TreeNode*,pair<int,int>>>q;
18        q.push({root,{0,0}});
19        while(!q.empty()){
20            auto [node,p]=q.front();
21            auto [hor,ver]=p;
22            q.pop();
23            
24            mp[hor][ver].insert(node->val);
25            if(node->left){
26                q.push({node->left,{hor-1,ver+1}});
27            }
28            if(node->right){
29                q.push({node->right,{hor+1,ver+1}});
30            }
31        }
32
33        for(auto p:mp){
34            vector<int>a;
35            for(auto it:p.second){//andar wla map
36                 for(auto i:it.second){
37                     a.push_back(i);
38                 }
39            }
40            ans.push_back(a);
41        }
42        return ans;
43    }
44};