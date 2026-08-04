class Solution {
public:
    int dp[501][501];
    int  solve(vector<int>&piles,int i,int j){
        if(i==j)return piles[i];
         
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

       int front=piles[i]+min(solve(piles,i,j-1),solve(piles,i+1,j));
       int end=piles[j]+min(solve(piles,i,j-1),solve(piles,i+1,j));
       return dp[i][j]=max(front,end);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        //n--->even number of piles
        //overall sum :odd
        
        //Alice makes the move first
       
       ///make your best move
       //but expect the least from the oppeonent
       
       //in case [ALICE STONES-BOB STONES]>0
       return solve(piles,0,n-1)>0;
    }
};