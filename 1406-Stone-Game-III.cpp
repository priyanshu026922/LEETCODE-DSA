class Solution {
private:
    int n;
public:
    int solve(vector<int>& s,int i, vector<int >&dp){
        //BASE CASE
        if(i==n)return 0;

        if(dp[i]!=-1)return dp[i];

        int maxi=INT_MIN;
        int val=0;
        for(int k=i;k<min(n,i+3);k++){
           val+=s[k];
           //iske aage jitna bhi hai usko BOB face krega
           //toh yha se miminum hi maan kr chlo ki milega aage beneifit ALICE KO
           
           maxi=max(maxi,val-solve(s,k+1,dp));

        }
        return dp[i]=maxi;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
          vector<int >dp(n+1,-1);
        //Alice goes first :
        //in each turn ,they both can take 1,2,3 stones at once (if available)
        
        //expect the least from the opponent :
        int x=solve(stoneValue,0,dp);
        if(x>0){
            return "Alice";
        }

        if(x<0){
            return "Bob";
        }

        return "Tie";
    }
};