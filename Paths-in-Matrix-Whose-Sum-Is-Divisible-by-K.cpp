1class Solution {
2public:
3int mdd=1e9+7;
4int solve(vector<vector<int>>& grid,int i,int j, int k,int mod, vector<vector<vector<int>>>&dp){
5    if(i<0||j<0){
6        return 0;
7    }
8    if(i==0&&j==0){
9        if((mod+grid[i][j])%k==0){
10            return 1;
11        }
12        return 0;
13    }
14    if(dp[i][j][mod]!=-1)return dp[i][j][mod];
15    
16    int l=0,u=0;
17     l+=solve(grid,i,j-1,k,(mod+grid[i][j])%k,dp);
18     u+=solve(grid,i-1,j,k,(mod+grid[i][j])%k,dp);
19    return dp[i][j][mod]=(l+u)%mdd;
20}
21
22    int numberOfPaths(vector<vector<int>>& grid, int k) {
23        int n=grid.size();
24        int m=grid[0].size();
25        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
26        int val=solve(grid,n-1,m-1,k,0,dp);
27        return val%mdd;
28    }
29};