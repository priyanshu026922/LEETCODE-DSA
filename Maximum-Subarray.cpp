1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int n=nums.size();
5        int sum=0;
6        int maxi=INT_MIN;
7        for(int i=0;i<n;i++){
8            sum+=nums[i];
9            if(sum>maxi){
10                maxi=sum;
11            }
12            if(sum<0){
13                sum=0;
14            }
15        }
16        return maxi;
17    }
18};