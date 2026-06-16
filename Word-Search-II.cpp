1 class TrieNode{
2    public:
3        string word="";
4        bool isEnd;
5        TrieNode *children[26];
6};
7
8
9class Trie{
10   //insert-->if not then insert or just move forward
11   //getNode->>>>just to intialize a new TRIENODE
12   public:
13    TrieNode* getNode(){
14        TrieNode *t=new TrieNode();
15
16        for(int i=0;i<26;i++){
17            t->children[i]=NULL;
18        }
19        t->word="";
20        return t;
21    }
22
23    void insert(TrieNode *root,string s){
24        TrieNode *temp=root;
25        for(int i=0;i<s.length();i++){
26            if(temp->children[s[i]-'a']==NULL){
27                temp->children[s[i]-'a']=getNode();//just to initialze its children
28            }
29
30            temp=temp->children[s[i]-'a'];
31        }
32
33        temp->isEnd=true;
34        temp->word=s;
35    }
36
37};
38
39
40
41class Solution {
42private:
43    int n,m;
44    int drow[4]={-1,0,1,0};
45    int dcol[4]={0,-1,0,1};
46public:
47
48  
49   void solve(vector<vector<char>>& board,int i,int j,TrieNode*root,string x,vector<string>&a){
50          if(i<0||j<0||j>=m||i>=n){
51              return;
52          }
53
54          char ch=board[i][j];
55         
56         if(board[i][j]=='#'||root->children[ch-'a']==NULL){
57            return;
58         }
59        
60         root=root->children[ch-'a'];
61         x+=ch;
62
63         if(root->isEnd){
64            a.push_back(x);
65            root->isEnd=false;
66         }
67         board[i][j]='#';
68         
69         for(int k=0;k<4;k++){
70            int new_i=i+drow[k];
71            int new_j=j+dcol[k];
72
73            if(new_i<0||new_j<0||new_i>=n||new_j>=m)continue;
74
75            solve(board,new_i,new_j,root,x,a);
76         }
77
78         board[i][j]=ch;
79   }
80   
81    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
82        n=board.size();
83        m=board[0].size();
84        Trie*t=new Trie();
85
86
87        TrieNode*root=t->getNode();
88
89        for(auto &it:words){
90            t->insert(root,it);
91        }
92
93        vector<string>a;
94        for(int i=0;i<n;i++){
95            for(int j=0;j<m;j++){
96                char ch=board[i][j];
97                string x="";
98                 if(root->children[ch-'a']!=NULL){
99                      solve(board,i,j,root,x,a);
100                 }
101            }
102        }
103
104
105      
106        return a;
107    }
108};