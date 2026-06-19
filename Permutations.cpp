1class Solution {
2public:
3    void solve(vector<int>& nums ,int i,vector<vector<int>>&ans){
4
5      if(i==nums.size()){
6        ans.push_back(nums);
7        return;
8      }
9      for(int j=i;j<nums.size();j++){
10        swap(nums[j],nums[i]);
11        solve(nums,i+1,ans);
12        swap(nums[j],nums[i]);
13      }
14    }
15    vector<vector<int>> permute(vector<int>& nums) {
16         vector<vector<int>>ans;
17         solve(nums,0,ans);
18         return ans;
19    }
20};