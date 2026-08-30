class Solution {
public:
     
     int dp[101][52][52];
      int  solve(vector<vector<int>>& cost,int i,int n,int a,int b){
        if(i==n){
            return 0;
        }
        if(dp[i][a][b]!=-1)return dp[i][a][b];
         
        int mini=INT_MAX;
        if(a>0){
          mini=min(mini,cost[i][0]+solve(cost,i+1,n,a-1,b));
        }

        if(b>0)mini=min(mini,cost[i][1]+solve(cost,i+1,n,a,b-1));
         
         return dp[i][a][b]=mini;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
           int n=costs.size();
      
        memset(dp,-1,sizeof(dp));

     return solve(costs,0,n,n/2,n/2);
    
    }
};