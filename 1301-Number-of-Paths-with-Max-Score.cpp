class Solution {
public:  
    int mod=1e9+7;
    int n;
    pair<int,int>solve(vector<string>& board,int i,int j, vector<vector<pair<int,int>>>&dp){
        if(i<0||j<0||j>=n||i>=n){
            return {0,0};
        }

        if(i==0&&j==0){
            board[i][j]='.';
            return {0,1};
        }

        if(board[i][j]=='X'){
            return {0,0};
        }

        if(dp[i][j]!=make_pair(-1,-1)){
            return dp[i][j];
        }

         char ch=board[i][j];
         int val=0;

         if(ch>='1'&&ch<='9'){
              val=ch-'0';
         }

          auto [scoreu,pu]=solve(board,i-1,j,dp);//up
          int upSum=val+scoreu;

          auto [scorel,pl]=solve(board,i,j-1,dp);//left
          int leftSum=val+scorel;

          auto [scored,pd]=solve(board,i-1,j-1,dp);//dia
          int dSum=val+scored;

          int maxi=max({upSum,leftSum,dSum});
          

          int path=0;
          if(maxi==upSum){
               path=(path+pu)%mod;
          }
 
          if(maxi==leftSum){
            path=(path+pl)%mod;
          }

          if(maxi==dSum){
            path=(path+pd)%mod;
          }
          return dp[i][j]={maxi,path};

    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        
        
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,make_pair(-1,-1)));
        pair<int,int> p=solve(board,n-1,n-1,dp);
        if(board[0][0]=='E'){
            return {0,0};
        }
        return {p.first,p.second};
    }
};