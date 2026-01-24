1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        int n=nums.size();
5        sort(begin(nums),end(nums));
6        int i=0;
7        int j=n-1;
8        int maxi=INT_MIN;
9        while(i<j){
10            int sum=nums[i]+nums[j];
11             maxi=max(maxi,sum);
12             i++;
13             j--;
14        }
15        return maxi;
16    }
17};