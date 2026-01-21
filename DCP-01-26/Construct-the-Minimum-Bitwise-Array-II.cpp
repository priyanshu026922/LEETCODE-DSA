1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4         int n=nums.size();
5         vector<int>ans(n,-1);
6         for(int j=0;j<n;j++){
7            if(nums[j]==2)continue;
8              int val=nums[j];
9              int mini=val;
10            for(int i=0;i<32;i++){
11                if(val&(1<<i)){
12                    int x=(val&(~(1<<i)));
13                    if((x|(x+1))==nums[j]){
14                              mini=min(mini,x);
15                    }
16                }
17            }
18            ans[j]=mini;
19
20         }
21         return ans;
22    }
23};