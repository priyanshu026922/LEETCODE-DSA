1class Solution {
2public:
3    typedef long long ll;
4    int n,m;
5    ll solve(vector<int>& robot, vector<ll>&pos,int i,int j, vector<vector<ll>>&dp){
6        if(i>=n)return 0;
7        if(j>=m)return 1e12;
8        
9        if(dp[i][j]!=-1)return dp[i][j];
10        ll nt=solve(robot,pos,i,j+1,dp);
11        ll t=abs(1LL*(robot[i]-pos[j]))+solve(robot,pos,i+1,j+1,dp);
12        return dp[i][j]=min(nt,t);
13    }
14
15    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
16        n=robot.size();
17      
18        sort(begin(robot),end(robot));
19        sort(begin(factory),end(factory));
20        vector<ll>pos;
21        
22            for(int i=0;i<factory.size();i++){
23                ll p=factory[i][0];
24                ll lim=factory[i][1];
25                for(int j=0;j<lim;j++){
26                    pos.push_back(p);
27                }
28            }
29
30          m=pos.size();
31          vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1));
32         
33        return solve(robot,pos,0,0,dp);
34    }
35};