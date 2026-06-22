1class Solution {
2private:
3   int n;
4   int dp[22][1011];
5public:
6    int solve(vector<int>& nums, int s,int i){
7        if(i==n-1){
8            if(nums[i]==0&&s==0){
9               return 2;
10            }else if(nums[i]==s||s==0){
11                return 1;
12            }
13            return 0;
14        }
15        if(dp[i][s]!=-1)return dp[i][s];
16        
17        int nt=solve(nums,s,i+1);
18
19        int t=0;
20        if(s>=nums[i]){
21            t=solve(nums,s-nums[i],i+1);
22        }
23        return dp[i][s]=t+nt;
24    }
25    int findTargetSumWays(vector<int>& nums, int target) {
26        n=nums.size();
27
28        int sum=accumulate(begin(nums),end(nums),0);
29        int s=sum-target;
30
31        if(s<0||s%2!=0){
32            return 0;
33        }
34        memset(dp,-1,sizeof(dp));
35        s/=2;
36
37        return solve(nums,s,0);
38    }
39};