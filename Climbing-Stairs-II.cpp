class Solution {
public:
    int solve(int i,vector<int>& costs, vector<int>&dp){
         
        if(i<0){
            return INT_MAX;
        }
       if(i==0){
            return 0 ;
        }
if(dp[i]!=-1)return dp[i];
        int v1=INT_MAX,v2=INT_MAX,v3=INT_MAX;
        if(i-1>=0) v1=costs[i]+1+solve(i-1,costs,dp);
       if(i-2>=0) v2=costs[i]+4+solve(i-2,costs,dp);
       if(i-3>=0) v3=costs[i]+9+solve(i-3,costs,dp);
        return dp[i]= min(v1,min(v2,v3));
    }

    int climbStairs(int n, vector<int>& costs) {
        costs.insert(begin(costs),0);
       int  x=costs.size();
         vector<int>dp(x+1,-1);
       return solve(x-1,costs,dp);
       
    }
};