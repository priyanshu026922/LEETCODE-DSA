class Solution {
public:
int solve(int n,vector<int>&dp){
   if(n==1)return 0;
   if(dp[n]!=-1)return dp[n];
   for(int j=1;j<n;j++){
    if(n%j==0){
        if(solve(n-j,dp)==0){
            return dp[n]=1;
        }
    }
   }
   return dp[n]=0;
}

bool divisorGame(int n) {
       vector<int>dp(n+1,-1);
       return solve(n,dp);
    }
};