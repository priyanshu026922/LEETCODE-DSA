class Solution {
public:
// int fact(int val,vector<int>&dp){
//     if(val<=1)return 1;

//     if(dp[val]!=-1)return dp[val];
//     return dp[val]=fact(val-1,dp)+fact(val-2,dp);
// }

// int solve(int root,int n,int c){
//     if(c==n){
//         return 0;
//     }

//    vector<int>dp(n+1,-1);

//    int val=fact(root-1,dp)*fact(n-root,dp);
//    return val+solve(root-1,n,c+1);
// }

int numTrees(int n) {
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[0]=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
               dp[i]+=(dp[j-1]*dp[i-j]);
            }
        }
        return dp[n];
    //   for(int i=1;i>=1;i--){
    //     int c=0;
    //     count+=solve(i,n,c);
    //   }
 }
};