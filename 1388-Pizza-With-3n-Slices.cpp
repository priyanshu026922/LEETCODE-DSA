class Solution {
public:
    int n;
    int dp[502][170];
    int s(vector<int>&slices,int i,int n,int cnt){
        if(cnt==0)return 0;
        if(i>n){
            return 0;
        }

        if(dp[i][cnt]!=-1)return dp[i][cnt];

        int t=slices[i]+s(slices,i+2,n,cnt-1);
        int nt=s(slices,i+1,n,cnt);

        return dp[i][cnt]=max(t,nt);
    }

    int solve(vector<int>&slices,int i,int n,int cnt){
    
      memset(dp,-1,sizeof(dp));
      return s(slices,i,n,cnt);
    }

    int maxSizeSlices(vector<int>& slices) {
        n=slices.size();
        return max(solve(slices,0,n-2,n/3),solve(slices,1,n-1,n/3));
    }
};