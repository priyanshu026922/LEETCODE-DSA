1class Solution {
2public:
3    int absDifference(vector<int>& nums, int k) {
4        int n=nums.size();
5        sort(begin(nums),end(nums));
6        int sum1=0;
7        int sum2=0;
8        for(int i=0;i<k;i++){
9            sum1+=nums[i];
10        }
11        for(int i=n-1;i>=n-k;i--){
12            sum2+=nums[i];
13        }
14        return abs(sum1-sum2);
15    }
16};