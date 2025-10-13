class Solution {
public:
int solve(int i,int tar,vector<int>&coins, vector<vector<int>>&dp){
   if(i==0){
    if(tar%coins[0]==0){
        return 1;
    }
    return 0;
   }
   if(dp[i][tar]!=-1)return dp[i][tar];
   int nt=solve(i-1,tar,coins,dp);
   int t=0;
   if(coins[i]<=tar){
    t=solve(i,tar-coins[i],coins,dp);
   }
   return dp[i][tar]=nt+t;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};