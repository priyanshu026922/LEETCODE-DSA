1class Solution {
2public:
3typedef long long ll;
4int mod=1e9+7;
5int n,m;
6   
7    pair<ll,ll>solve(int i,int j,vector<vector<int>>& grid,vector<vector<pair<ll,ll>>>&dp){
8
9         if(i==0&&j==0){
10             return {grid[0][0],grid[0][0]};
11         }
12
13         if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) return dp[i][j];
14
15         ll maxVal=LLONG_MIN;
16         ll minVal=LLONG_MAX;
17         
18         
19         if(i-1>=0){
20         pair<ll,ll>p1=solve(i-1,j,grid,dp);
21         maxVal=max({maxVal,grid[i][j]*p1.first,grid[i][j]*p1.second});
22         minVal=min({minVal,grid[i][j]*p1.first,grid[i][j]*p1.second});
23         }
24
25         if(j-1>=0){
26         pair<ll,ll>p2=solve(i,j-1,grid,dp);
27         maxVal=max({maxVal,grid[i][j]*p2.first,grid[i][j]*p2.second});
28         minVal=min({minVal,grid[i][j]*p2.first,grid[i][j]*p2.second});
29         }
30        
31         return dp[i][j]={maxVal,minVal};
32    }
33
34    int maxProductPath(vector<vector<int>>&grid) {
35        n=grid.size();
36        m=grid[0].size();
37        vector<vector<pair<ll,ll>>>dp(n,vector< pair<ll,ll> >(m,make_pair(LLONG_MIN, LLONG_MAX)) );
38        pair<ll,ll> val= solve(n-1,m-1,grid,dp);
39        if(val.first<0)return -1;
40
41        return val.first%mod;
42    }
43};