class Solution {
public:
typedef long long ll;
int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
    if(j-i+1<3){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
   ll res=LLONG_MAX;
    for(int k=i+1;k<j;k++){
        ll wt=1LL*v[i]*v[j]*v[k]+1LL*solve(v,i,k,dp)+1LL*solve(v,k,j,dp);
        res=min(res,wt);
    }
    return dp[i][j]=(int)res;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};