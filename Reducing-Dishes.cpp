1class Solution {
2public:
3    int n;
4
5    int solve(vector<int>& s,int ind,int lvl,vector<vector<int>>&dp){
6        if(ind==n){
7             return 0;
8        }
9        if(dp[ind][lvl]!=-1)return dp[ind][lvl];
10        int t=s[ind]*lvl+solve(s,ind+1,lvl+1,dp);
11        int nt=solve(s,ind+1,lvl,dp);
12        return dp[ind][lvl]=max(nt,t);
13    }
14    int maxSatisfaction(vector<int>& satisfaction) {
15        n=satisfaction.size();
16        vector<vector<int>>dp(n+1,vector<int>(502,-1));
17        sort(begin(satisfaction),end(satisfaction));
18        return solve(satisfaction,0,1,dp);
19    }
20};