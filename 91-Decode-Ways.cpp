class Solution {
public:
    int n;
    int dp[101];
    int solve(string &s,int ind){
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1)return dp[ind];

        string st="";
        int cnt=0;
        for(int i=ind;i<min(n,ind+2);i++){
            
            if(s[ind]=='0')return 0;
            st+=s[i];
            int x=stoi(st);
            // cout<<x<<endl;
            if(x<=26){
                cnt+=solve(s,i+1);
            }
        }
        return dp[ind]=cnt;
    }

    int numDecodings(string s) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};