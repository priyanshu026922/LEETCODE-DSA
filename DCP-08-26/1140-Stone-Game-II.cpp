class Solution {
public:
    int n;
    int solve(vector<int>&piles,int i,int m,int turn,vector<vector<vector<int>>>&dp){
        if(i>=n)return 0;
         if(dp[i][m][turn]!=-1)return dp[i][m][turn];
        int maxi=(turn==1)?-1:INT_MAX;
        int val=0;
        for(int j=1;j<=min(2*m,n-i);j++){
            val+=piles[i+j-1];  
            if(turn==1){//ALICE
               maxi=max(maxi,val+solve(piles,i+j,max(m,j),0,dp));
            }else{
               maxi=min(maxi,solve(piles,i+j,max(m,j),1,dp));
            }
        }
        
        return dp[i][m][turn]=maxi;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2*n,vector<int>(2,-1)));
        return solve(piles,0,1,1,dp);
    }
};