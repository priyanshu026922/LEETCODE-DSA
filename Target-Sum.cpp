class Solution {
public:
int solve(int ind,vector<int>& nums,int tar,  vector<vector<int>>&dp){
    
    if(ind==0){
        if(tar==0&&nums[0]==0)return 2;
        if(tar==0||tar==nums[0])return 1;
        return 0;
    }
    if(dp[ind][tar]!=-1)return dp[ind][tar];
    int nt=solve(ind-1,nums,tar,dp);
    int t=0;
    if(nums[ind]<=tar){
        t=solve(ind-1,nums,tar-nums[ind],dp);
    }
    return dp[ind][tar]=nt+t;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int x=accumulate(begin(nums),end(nums),0);
        if(x-target<0||(x-target)%2!=0)return 0;
        int req=(x-target)/2;
        vector<vector<int>>dp(n,vector<int>(req+1,-1));
        
        return solve(n-1,nums,req,dp);
    }
};