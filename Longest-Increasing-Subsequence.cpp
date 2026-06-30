1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>dp(n+1,1);
6        
7        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
8
9//         for(int i=n-1;i>=0;i--){
10//             vector<int>curr(n+1,0);
11//             for(int prev=i-1;prev>=-1;prev--){
12//                 int l=nxt[prev+1];
13//                 if(prev==-1||nums[i]>nums[prev]){
14//                     l=max(l,1+nxt[i+1]);
15// ;                }
16//                 curr[prev+1]=l;
17//             }
18//             nxt=curr;
19//         }
20//         return nxt[0];
21       
22       int maxi=0;
23       for(int i=0;i<n;i++){
24            for(int prev=0;prev<i;prev++){
25                if(nums[i]>nums[prev]){
26                    dp[i]=max(dp[i],1+dp[prev]);
27                }
28            }
29          maxi=max(maxi,dp[i]);
30       }
31       return maxi;
32    }
33};