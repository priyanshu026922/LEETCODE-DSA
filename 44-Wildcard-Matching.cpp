class Solution {
public:
    int n,m;
    int dp[2001][2001];
    bool solve(string &s,string &p,int i,int j){
       if(j<0){
           return i<0;   
       }

       if(i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*')return false;
            }
            return true;
       }

       if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==p[j]){
            return dp[i][j]=solve(s,p,i-1,j-1);
        }

        if(p[j]=='?'){
            return dp[i][j]=solve(s,p,i-1,j-1);
        }

        if(p[j]=='*'){
            return dp[i][j]=solve(s,p,i-1,j)|solve(s,p,i,j-1);
        }

        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        n=s.length();
        m=p.length();
       memset(dp,-1,sizeof(dp));
        return solve(s,p,n-1,m-1);
    }
};