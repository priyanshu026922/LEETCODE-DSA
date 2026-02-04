1class Solution {
2public:
3typedef long long ll;
4int n;
5vector<vector<ll>>dp;
6ll solve(int i,int trend,vector<int>& nums){
7    if(i>=n){
8            if(trend==3){
9                return 0;
10            }
11            return LLONG_MIN/2;
12    }
13    if(dp[i][trend]!=LLONG_MIN){
14        return dp[i][trend];
15    }
16    ll take=LLONG_MIN/2;
17    ll skip=LLONG_MIN/2;
18    if(trend==0){
19        skip=solve(i+1,trend,nums);
20    }
21    if(trend==3){
22        take=nums[i];
23    }
24    if(i+1<n){
25    int curr=nums[i];
26    int nxt=nums[i+1];
27             if(trend==0&&nxt>curr){
28                take=max(take,curr+solve(i+1,1,nums));
29             }else if(trend==1){
30                if(nxt>curr){
31                    take=max(take,curr+solve(i+1,1,nums));
32                }else if(nxt<curr){
33                    take=max(take,curr+solve(i+1,2,nums));
34                }
35             }else if(trend==2){
36                if(nxt<curr){
37                    take=max(take,curr+solve(i+1,2,nums));
38                }else if(nxt>curr){
39                    take=max(take,curr+solve(i+1,3,nums));
40                }
41             }else if(trend==3&&nxt>curr){
42                      take=max(take,curr+solve(i+1,3,nums));
43             }
44    }
45    return dp[i][trend]=max(take,skip);
46}
47    ll maxSumTrionic(vector<int>& nums) {
48        n=nums.size();
49        dp.assign(n+1,vector<ll>(4,LLONG_MIN));
50        return solve(0,0,nums);
51    }
52};