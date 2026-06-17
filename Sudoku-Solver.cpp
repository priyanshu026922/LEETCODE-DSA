1class Solution {
2private:
3int n,m;
4public:
5  bool isSafe(int r,int c,vector<vector<char>>& board,char &ch){
6    for(int i=0;i<9;i++){
7            if(board[r][i]==ch){
8                return false;
9            }
10            if(board[i][c]==ch){
11                return false;
12            }
13
14            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch){
15                return false;
16            }
17    }
18    return true;
19  }
20   bool solve(vector<vector<char>>& board){
21      
22         for(int i=0;i<n;i++){
23            for(int j=0;j<m;j++){
24                if(board[i][j]=='.'){
25                    for(char ch='1';ch<='9';ch++){
26                        if(isSafe(i,j,board,ch)){
27                            board[i][j]=ch;
28                            if(solve(board)){
29                                return true;
30                            }
31                            board[i][j]='.';
32                        }
33                    }
34                    return false;
35                }
36            }
37         }
38
39         return true;
40   }
41    void solveSudoku(vector<vector<char>>& board) {
42        n=board.size();
43        m=board[0].size();
44        solve(board);
45    }
46};