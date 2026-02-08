1class Solution {
2public:
3
4int minDeletionSize(vector<string>& strs) {
5        int n=strs.size();
6        int m=strs[0].length();
7        
8        int LIS=1;
9
10        vector<int>dp(m,1);
11        for(int i=0;i<m;i++){
12            for(int j=0;j<i;j++){
13
14                bool isvalid=true;
15                for(int k=0;k<n;k++){
16                     if(strs[k][j]>strs[k][i]){
17                        isvalid=false;
18                     }
19                }
20                if(isvalid){
21                    dp[i]=max(dp[i],1+dp[j]);
22                }
23            }
24            LIS=max(LIS,dp[i]);
25        }
26return m-LIS;
27    }
28};