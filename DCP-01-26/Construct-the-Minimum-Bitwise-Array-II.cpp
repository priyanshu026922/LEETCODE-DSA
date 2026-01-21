1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4         int n=nums.size();
5         vector<int>ans(n,-1);
6         for(int j=0;j<n;j++){
7            if(nums[j]==2)continue;
8              int val=nums[j];
9              bool found=true;
10            for(int i=0;i<32;i++){
11                if(val&(1<<i)){
12                    continue;
13                }
14                int prev=i-1;
15                int x=(val^(1<<prev));
16                ans[j]=x;
17                break;
18            }
19        
20         }
21         return ans;
22    }
23};
24
25
26// int x=(val&(~(1<<i)));
27//                     if((x|(x+1))==nums[j]){
28//                               mini=min(mini,x);
29//                     }