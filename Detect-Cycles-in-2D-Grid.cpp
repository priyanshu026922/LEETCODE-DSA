1class Solution {
2public:
3    int n,m;
4    int drow[4]={-1,0,1,0};
5    int dcol[4]={0,-1,0,1};
6    bool solve(char ch,int i,int j,int last_i,int last_j,int cnt,vector<vector<char>>& grid,vector<vector<int>>&vis){
7
8        vis[i][j]=1;
9
10        bool check=false;
11        for(int k=0;k<4;k++){
12             int new_i=drow[k]+i;
13             int new_j=dcol[k]+j;
14
15            if(new_i>=0&&new_i<n&&new_j>=0&&new_j<m){
16                 
17                 if(grid[new_i][new_j]==grid[i][j]&&!(new_i==last_i&&new_j==last_j)){
18
19                    if(vis[new_i][new_j]&&cnt+1>=4){
20                           return true;
21                    }
22
23                    if(solve(grid[i][j],new_i,new_j,i,j,cnt+1,grid,vis)){
24                        return true;
25                    }
26                 } 
27
28
29            }
30        }
31
32        return false;
33    }
34
35    bool containsCycle(vector<vector<char>>& grid) {
36        n=grid.size();
37        m=grid[0].size();
38        vector<vector<int>>vis(n,vector<int>(m,0));
39        for(int i=0;i<n;i++){
40            for(int j=0;j<m;j++){
41                char ch=grid[i][j];
42                if(!vis[i][j]){
43                    if(solve(ch,i,j,i,j,0,grid,vis)){
44                        return true;
45                    }
46                    
47                }
48            }
49        }
50    
51
52       return false;
53    }
54};