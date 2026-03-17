1class Solution {
2public:
3    vector<int> countBits(int n) {
4        vector<int>dp(n+1,0);
5         int s=1;
6        for(int i=1;i<=n;i++){
7          if(s*2==i){
8            s=i;
9          }
10          dp[i]=dp[i-s]+1;
11        }
12        return dp;
13    }
14};