1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        
5        int n=nums.size();
6        vector<int>ans(n,-1);
7        for(int i=0;i<n;i++){
8            int x=nums[i];
9            for(int val=0;val<x;val++){
10                if((val|(val+1))==x){
11                    ans[i]=val;
12                    break;
13                }
14            }
15        }
16        return ans;
17    }
18};