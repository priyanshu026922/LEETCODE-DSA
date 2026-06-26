1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13    // Encodes a tree to a single string.
14    string serialize(TreeNode* root) {
15        if(!root){
16            return "NULL";
17        }
18         
19
20        //using preorder traversal;
21        string x=to_string(root->val);
22
23        return x+","+serialize(root->left)+","+serialize(root->right);
24    }
25     
26    TreeNode *solve(queue<string>&q){
27        string s=q.front();
28
29        q.pop();
30        if(s=="NULL"){
31            return NULL;
32        }
33        TreeNode *root=new TreeNode(stoi(s));
34
35        root->left=solve(q);
36        root->right=solve(q);
37
38        return root;
39    }
40    // Decodes your encoded data to tree.
41    TreeNode* deserialize(string data) {
42        queue<string>q;
43
44        string s;
45
46        for(int i=0;i<data.size();i++){
47            if(data[i]==','){
48                q.push(s);
49                s="";
50                continue;
51            }
52
53            s+=data[i];
54        }
55
56        if(s.size()!=0){
57            q.push(s);
58        }
59
60        return solve(q);
61    }
62};
63
64// Your Codec object will be instantiated and called as such:
65// Codec ser, deser;
66// TreeNode* ans = deser.deserialize(ser.serialize(root));