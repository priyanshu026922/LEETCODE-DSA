1class Solution {
2public:
3int n,m;
4int dp[502][502][3];
5    int solve(int i,int j,vector<vector<int>>& coins,int cnt){
6        if(i<0||j<0||i>=n||j>=m){
7            return INT_MIN;
8        }
9
10        if(i==0&&j==0){
11            if(coins[i][j]<0&&cnt>0){
12                return 0;
13            }
14            return coins[i][j];
15        }
16        if(dp[i][j][cnt]!=INT_MIN)return dp[i][j][cnt];
17       
18        int  take=coins[i][j]+max(solve(i-1,j,coins,cnt),solve(i,j-1,coins,cnt));
19         int skip=INT_MIN;
20        int up=INT_MIN,left=INT_MIN;
21        if(coins[i][j]<0&&cnt>0){
22            up=solve(i-1,j,coins,cnt-1);
23            left=solve(i,j-1,coins,cnt-1);
24             skip=max(up,left);
25        }
26        return dp[i][j][cnt]=max(take,skip);
27    }
28
29    int maximumAmount(vector<vector<int>>& coins) {
30         n=coins.size();
31         m=coins[0].size();
32        for(int i=0;i<502;i++){
33            for(int j=0;j<502;j++){
34                for(int k=0;k<3;k++){
35                    dp[i][j][k]=INT_MIN;
36                }
37            }
38        }
39        return solve(n-1,m-1,coins,2);
40    }
41};