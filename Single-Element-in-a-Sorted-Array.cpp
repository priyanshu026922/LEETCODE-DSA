1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4        int x=0;
5        for(int i=0;i<nums.size();i++){
6            x=x^nums[i];
7        }
8        return x;
9    }
10};