1class Solution {
2public:
3    int n,m;
4    int solve(vector<vector<int>>&grid,int cost,int i,int j,vector<vector<vector<int>>>&dp){
5         if(i<0||j<0||i>=n||j>=m){
6            return INT_MIN;
7         }
8
9          int C=0;
10         if(grid[i][j]==0)C=0;
11         if(grid[i][j]==1)C=1;
12         if(grid[i][j]==2)C=1;
13          
14          if(i==n-1&&j==m-1){
15              if(cost>=C){
16                 return grid[i][j];
17              }
18              return INT_MIN;
19          }
20
21         if(dp[i][j][cost]!=-1)return dp[i][j][cost];
22
23         int right=INT_MIN;
24         int down=INT_MIN;
25        
26         if(cost-C>=0){
27        
28            down=grid[i][j]+solve(grid,cost-C,i+1,j,dp);
29            right=grid[i][j]+solve(grid,cost-C,i,j+1,dp);
30         }
31
32         return dp[i][j][cost]=max(right,down);
33    }
34    int maxPathScore(vector<vector<int>>& grid, int k) {
35        n=grid.size();
36        m=grid[0].size();
37         
38        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
39        int s=solve(grid,k,0,0,dp);
40        cout<<INT_MIN<<endl;
41        if(s<0)return -1;
42
43        return s; //{grid,k,i,j,cost};
44    }
45};