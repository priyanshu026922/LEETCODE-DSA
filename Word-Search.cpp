1class Solution {
2private:
3   int n,m,N;
4public:
5    int drow[4]={-1,0,1,0};
6    int dcol[4]={0,-1,0,1};
7    int dp[7][8];
8    bool solve(vector<vector<char>>& board,int i,int j,string s, string word,  int idx){
9        
10       if(i<0||j<0||i>=n||j>=m){
11          return false;
12       }
13        
14       
15       if(board[i][j]!=word[idx]){
16          return false;;
17       }
18
19       if(idx==word.length()-1){
20            return true;
21       }
22
23    
24       s+=board[i][j];
25       board[i][j]='#';
26      
27       for(int k=0;k<4;k++){
28         int new_i=drow[k]+i;
29         int new_j=dcol[k]+j;
30            
31            
32            if(new_i<0||new_j<0||new_i>=n||new_j>=m){
33                continue;
34            }
35           
36            if(board[new_i][new_j]!='#'){
37                if(solve(board,new_i,new_j,s,word,idx+1)){
38                    return true;
39                }
40            }
41
42
43       }
44
45       board[i][j]=word[idx];
46       s.pop_back();
47
48       return false;
49
50    }
51    bool exist(vector<vector<char>>& board, string word) {
52        n=board.size();
53        m=board[0].size();
54
55           for(int i=0;i<n;i++){
56                for(int j=0;j<m;j++){
57
58                    if(solve(board,i,j,"",word,0)){
59                        return true;
60                    }
61                }
62           }
63        return false;
64    }
65};