1class Solution {
2public:
3typedef long long ll;
4int n;
5//1--normal transaction
6//2---short selling
7    ll solve(vector<int>&prices,int i,int state,int k, vector<vector<vector<ll>>>&dp){
8        if(i==n){
9             if(state==0){
10                return 0;
11             }
12             return INT_MIN;
13        }
14        if(dp[i][state][k]!=INT_MIN)return dp[i][state][k];
15
16            ll t=INT_MIN;
17            ll nt=solve(prices,i+1,state,k,dp);
18               
19            if(k>0){
20                if(state==1){
21                    t=prices[i]+solve(prices,i+1,0,k-1,dp);
22                }
23                else if(state==2){
24                     t=-prices[i]+solve(prices,i+1,0,k-1,dp);
25                }else{
26                    t=max(prices[i]+solve(prices,i+1,2,k,dp),-prices[i]+solve(prices,i+1,1,k,dp));
27                }
28             }
29        return dp[i][state][k]=max(t,nt);
30    }
31
32    ll maximumProfit(vector<int>& prices, int k) {
33         n=prices.size();
34         vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(3,vector<ll>(k+1,INT_MIN)));
35        return solve(prices,0,0,k,dp);
36    }
37};