1class Solution {
2public:
3    int mod=1e9+7;
4    int solve(int oneL,int zeroL,bool last,int limit,vector<vector<vector<int>>>&dp){
5           if(oneL==0&&zeroL==0){
6              return 1;
7           }
8            
9           if( dp[oneL][zeroL][last]!=-1)return  dp[oneL][zeroL][last];
10           int res=0;
11           if(last==1){
12             for(int len=1;len<=min(limit,zeroL);len++){
13                  res=(res+solve(oneL,zeroL-len,0,limit,dp))%mod;
14             }
15           }else{
16             for(int len=1;len<=min(limit,oneL);len++){
17                  res=(res+solve(oneL-len,zeroL,1,limit,dp))%mod;
18             }
19           }
20           return dp[oneL][zeroL][last]=res;
21    }
22    int numberOfStableArrays(int zero, int one, int limit) {
23        vector<vector<vector<int>>>dp(zero+1,vector<vector<int>>(one+1,vector<int>(2,-1)));
24        int a1=solve(zero,one,1,limit,dp);
25        int a2=solve(zero,one,0,limit,dp);
26        return (a1+a2)%mod;
27    }
28};