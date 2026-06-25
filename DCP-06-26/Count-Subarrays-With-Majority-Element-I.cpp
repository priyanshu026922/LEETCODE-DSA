1class Solution {
2public:
3    int n;
4    int countMajoritySubarrays(vector<int>& nums, int target) {
5         n=nums.size();
6        int ans=0;
7         for(int i=0;i<n;i++){
8            int cnt=0;
9            for(int j=i;j<n;j++){
10                if(nums[j]==target){
11                    cnt++;
12                }
13
14                if(cnt>(j-i+1)/2){
15                    ans++;
16                }
17            }
18         }
19         return ans;
20    }
21};