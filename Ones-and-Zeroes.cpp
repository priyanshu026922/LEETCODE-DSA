1class Solution {
2public:
3int q;
4//m-------at most m-zero
5//n-------at most n-ones
6int solve(vector<string>&strs,int ind,int n,int m,vector<vector<vector<int>>>&dp){
7    
8    if(ind<0){
9        return 0;
10    } 
11    if(dp[ind][n][m]!=-1)return dp[ind][n][m];
12
13   int t=INT_MIN;
14   int val=ranges::count(strs[ind],'1');
15   int p=strs[ind].length();
16
17   if((n-val)>=0&& (m-p+val)>=0){
18    
19        t=1+solve(strs,ind-1,n-val,m-p+val,dp);
20   }
21
22    int nt=solve(strs,ind-1,n,m,dp);
23    return dp[ind][n][m]=max(t,nt);
24}
25    int findMaxForm(vector<string>& strs, int m, int n) {
26          q=strs.size();
27          vector<vector<vector<int>>>dp(601,vector<vector<int>>(101,vector<int>(101,-1)));
28          return solve(strs,q-1,n,m,dp);
29    }
30};