1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n=nums.size();
5        int maxi=0;
6        for(int i=0;i<n;i++){
7           if(i>maxi)return false;
8           maxi=max(maxi,i+nums[i]);
9            
10        }
11        return true;
12    }
13};