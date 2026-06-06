1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int l=0;
5        int n=nums.size();
6        vector<int>ans;
7        int sum=accumulate(begin(nums),end(nums),0);
8        for(int i=0;i<n;i++){
9            int r=sum-nums[i]-l;
10            int val=abs(l-r);
11            l+=nums[i];
12            ans.push_back(val);
13        }
14        return ans;
15    }
16};