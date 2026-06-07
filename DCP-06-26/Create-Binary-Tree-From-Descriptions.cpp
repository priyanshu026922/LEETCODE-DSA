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
14  
15    TreeNode* createBinaryTree(vector<vector<int>>& d) {
16
17        if(d.size()==0){
18            return NULL;
19        }
20        
21        int val=0;
22        unordered_map<int,int>mp2;
23        for(auto &it:d){
24           int x=it[0];
25           int y=it[1];
26           int z=it[2];
27           mp2[y]=x;
28          if(mp2.find(x)==mp2.end()) mp2[x]=0;
29        }
30
31        for(auto &it:mp2){
32            if(it.second==0){
33                val=it.first;
34                break;
35            }
36        }
37        
38        unordered_map<int ,TreeNode*>mp;
39        for(auto &it:d){
40           int x=it[0];
41           int y=it[1];
42           int z=it[2];
43            
44           TreeNode*n1;
45           if(mp.find(x)!=mp.end()){
46               n1=mp[x];
47           }else{
48              n1=new TreeNode(x);
49              mp[x]=n1;
50           }
51
52           TreeNode*n2;
53           if(mp.find(y)!=mp.end()){
54               n2=mp[y];
55           }else{
56              n2=new TreeNode(y);
57              mp[y]=n2;
58           }
59
60           if(z==1){
61              n1->left=n2;
62            //   cout<<"1"<<endl;
63           }else{
64              n1->right=n2;
65            //   cout<<"2"<<endl;
66           } 
67        }
68        return mp[val];
69      
70
71    }
72};