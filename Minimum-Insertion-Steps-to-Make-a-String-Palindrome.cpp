1class Solution {
2public:
3    int solve(int n,int m,string &x,string &y){
4        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
5
6        for(int i=1;i<=n;i++){
7            for(int j=1;j<=n;j++){
8                if(x[i-1]==y[j-1]){
9                    dp[i][j]=1+dp[i-1][j-1];
10                }else{
11                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
12                }
13            }
14        }
15
16        return dp[n][n];
17    }
18    int minInsertions(string s) {
19        int n=s.length();
20        string m=s;
21        reverse(begin(m),end(m));
22        int x=solve(n,n,s,m);
23
24
25        return n-x;
26    }
27};