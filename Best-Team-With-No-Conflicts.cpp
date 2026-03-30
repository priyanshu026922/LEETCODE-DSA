1class Solution {
2public:
3    int n;
4    int solve(int i,int prev,vector<pair<int,int>>&vec,vector<vector<int>>&dp){
5        if(i==n)return 0;
6
7        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
8        
9        //vec--->{age,score};
10        int nt=solve(i+1,prev,vec,dp);
11        int t=INT_MIN;
12        if(prev==-1||vec[i].second>=vec[prev].second){
13              t=vec[i].second+solve(i+1,i,vec,dp);
14        }
15        return dp[i][prev+1]=max(t,nt);
16    } 
17
18    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
19        n=scores.size();
20        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
21        vector<pair<int,int>>vec(n);
22        
23        for(int i=0;i<n;i++){
24            vec[i]={ages[i],scores[i]};
25        }
26
27        sort(begin(vec),end(vec));
28        return solve(0,-1,vec,dp);
29    }
30};