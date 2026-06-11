1class Solution {
2public:
3int n;
4    int solve(vector<int>&c,int i,int target,vector<int>&a,vector<vector<int>>&dp){
5        if(target==0){
6            return 1;
7        }
8        
9
10        if(i==n){
11          if(target==0){
12           return 1;
13          }
14          return 0;
15        }
16
17        if(target<0){
18           return 0;
19        }
20
21        if(dp[i][target]!=-1){
22             return dp[i][target];
23        }
24        int ans=0;
25        for(int j=0;j<n;j++){
26            if(c[j]>target)break;
27            a.push_back(c[j]);
28            ans+=solve(c,j,target-c[j],a,dp);
29            a.pop_back();
30        }
31
32
33
34        return dp[i][target]=ans;
35
36        
37    }
38
39    int combinationSum4(vector<int>& nums, int target) {
40
41
42         sort(begin(nums),end(nums));
43        vector<vector<int>>ans;
44        vector<int>a;
45        n=nums.size();
46
47        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
48        return solve(nums,0,target,a,dp);
49    }
50};