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
12class BSTIterator_next{
13  public:
14    stack<TreeNode*>s;
15    BSTIterator_next(TreeNode*node){
16          pushAll(node);
17    }
18
19    void pushAll(TreeNode *temp){
20        
21        while(temp){
22            s.push(temp);
23            temp=temp->left;
24        }
25    }
26
27   
28
29    int next(){
30        TreeNode * nextele=s.top();
31        s.pop();
32       pushAll(nextele->right);
33        return nextele->val;
34    }
35};
36
37
38class BSTIterator_before{
39  public:
40    stack<TreeNode*>s;
41    BSTIterator_before(TreeNode*node){
42          pushAll(node);
43    }
44
45    void pushAll(TreeNode *temp){
46        
47        while(temp){
48            s.push(temp);
49            temp=temp->right;
50        }
51    }
52
53    
54    int before(){
55        TreeNode * nextele=s.top();
56        s.pop();
57       pushAll(nextele->left);
58        return nextele->val;
59    }
60};
61
62class Solution {
63public:
64  
65    bool findTarget(TreeNode* root, int k) {
66        if(!root){
67            return false;
68        }
69       BSTIterator_next  b1(root);
70       BSTIterator_before b2(root);
71    
72       int i=b1.next();
73       int j=b2.before();
74       while(i<j){
75        if(i+j==k)return true;
76        else if(i+j<k){
77            i=b1.next();
78        }else{
79            j=b2.before();
80        }
81       }
82       return false;
83
84    }
85};