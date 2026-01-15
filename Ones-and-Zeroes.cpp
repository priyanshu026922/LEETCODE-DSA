1class Solution {
2public:
3int q;
4
5int count1(string &x){
6    int c=0;
7    for(int i=0;i<x.length();i++){
8       if(x[i]=='1')c++;
9    }
10    return c;
11}
12
13//m-------at most m-zero
14//n-------at most n-ones
15int solve(vector<string>&strs,int ind,int n,int m,vector<vector<vector<int>>>&dp){
16    
17    if(ind<0){
18        return 0;
19    } 
20    if(dp[ind][n][m]!=-1)return dp[ind][n][m];
21
22   int t=INT_MIN;
23   int val=count1(strs[ind]);
24   int p=strs[ind].length();
25   
26   if((n-val)>=0&& (m-p+val)>=0){
27    
28        t=1+solve(strs,ind-1,n-val,m-p+val,dp);
29   }
30
31    int nt=solve(strs,ind-1,n,m,dp);
32    return dp[ind][n][m]=max(t,nt);
33}
34    int findMaxForm(vector<string>& strs, int m, int n) {
35          q=strs.size();
36          vector<vector<vector<int>>>dp(601,vector<vector<int>>(101,vector<int>(101,-1)));
37          return solve(strs,q-1,n,m,dp);
38    }
39};