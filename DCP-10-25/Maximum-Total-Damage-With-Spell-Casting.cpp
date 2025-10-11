class Solution {
public:
typedef long long ll;
unordered_map<ll,ll>mp;
int n;
    ll solve(vector<int>& power,int i,vector<ll>&dp){
        if(i>=n){
            return 0;
        }

if(dp[i]!=-1)return dp[i];

    ll nt=solve(power,i+1,dp);
    int j=lower_bound(begin(power)+i+1,end(power),power[i]+3)-begin(power);

    ll t=power[i]*mp[power[i]]+solve(power,j,dp);
    return dp[i]=max(t,nt);
    }
   ll maximumTotalDamage(vector<int>& power) {
        sort(begin(power),end(power));
     n=power.size();
      vector<ll>dp(n+1,-1);
        
        for(int i=0;i<n;i++){
            mp[power[i]]++;
        }
return solve(power,0,dp);
    }
};