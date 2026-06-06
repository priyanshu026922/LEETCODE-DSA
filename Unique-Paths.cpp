1class Solution {
2public:
3    int dp[101][101];
4    int solve(int i,int j,int n,int m){
5        if(i<0||i>=n||j<0||j>=m){
6            return 0;
7        }
8
9        if(i==n-1&&j==m-1){
10            return 1;
11        }
12        if(dp[i][j]!=-1)return dp[i][j];
13         
14         int l=solve(i,j+1,n,m);
15         int r=solve(i+1,j,n,m);
16         return dp[i][j]=l+r;
17    }
18    int uniquePaths(int m, int n) {
19        for(int i=0;i<101;i++){
20            for(int j=0;j<101;j++){
21                dp[i][j]=-1;
22            }
23        }
24        return solve(0,0,m,n);
25    }
26};