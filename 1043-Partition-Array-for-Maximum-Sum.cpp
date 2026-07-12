class Solution {
public:
    int n;
    int dp[501];
    int solve(vector<int>&arr,int i,int k){
        if(i==n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        
        int m=arr[i];
        int sum=INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            m=max(m,arr[j]);
            sum=max(sum,(j-i+1)*m+solve(arr,j+1,k));
        }

        return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
};