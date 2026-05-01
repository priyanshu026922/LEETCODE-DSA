1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>dp(n,0);
6        int sum=accumulate(begin(nums),end(nums),0);
7        int s=0;
8        for(int i=0;i<n;i++){
9            s+=i*nums[i];
10        }
11        int maxi=s;
12        dp[0]=s;
13        for(int i=1;i<n;i++){
14               dp[i]=dp[i-1]+sum-n*nums[n-i];
15               maxi=max(maxi,dp[i]);
16        }
17        
18        return maxi;
19    }
20};