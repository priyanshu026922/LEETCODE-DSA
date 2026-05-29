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
14    int kthSmallest(TreeNode* root, int k) {
15        
16        TreeNode*curr=root;
17        int cnt=0;
18        int ans=-1;
19        while(curr){
20            if(!curr->left){
21                 cnt++;
22                 if(cnt==k){
23                    ans=curr->val;
24                 }
25                curr=curr->right;
26            }else{//curr->left exists
27                TreeNode*prev=curr->left;
28                while(prev->right&&prev->right!=curr){
29                    prev=prev->right;
30                }
31
32                if(!prev->right){
33                    prev->right=curr;
34                    curr=curr->left;
35                }
36
37                else {//prev->right NOT NULL
38                     prev->right=NULL;
39                     cnt++;
40                     if(cnt==k){
41                        ans= curr->val;
42                     }
43                      
44                     curr=curr->right;
45                    
46                }
47
48            }
49
50           
51        }
52        return ans;
53    }
54};