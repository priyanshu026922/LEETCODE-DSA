1class Solution {
2public:
3    int minimumOperations(vector<int>& nums) {
4        int n=nums.size();
5        int s=0;
6        for(int i=0;i<n;i++){
7            if(nums[i]%3!=0)s++;
8        }
9        return s;
10    }
11};