class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]&&1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else  if(nums[prev]<nums[i]&&1+dp[prev]==dp[i]){
                    dp[i]=1+dp[prev];
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)c+=cnt[i];
        }
        return c;
    }
};