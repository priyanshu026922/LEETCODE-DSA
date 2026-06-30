1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>nxt(n+1,0);
6        
7        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
8
9        for(int i=n-1;i>=0;i--){
10            vector<int>curr(n+1,0);
11            for(int prev=i-1;prev>=-1;prev--){
12                int l=nxt[prev+1];
13                if(prev==-1||nums[i]>nums[prev]){
14                    l=max(l,1+nxt[i+1]);
15;                }
16                curr[prev+1]=l;
17            }
18            nxt=curr;
19        }
20        return nxt[0];
21    }
22};