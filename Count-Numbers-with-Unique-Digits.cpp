1class Solution {
2public:
3    int countNumbersWithUniqueDigits(int n) {
4       vector<int>dp(n+1,0);
5       if(n==0)return 1;
6       if(n==1)return 10;
7       dp[0]=1;
8       dp[1]=10;
9
10       for(int i=2;i<=n;i++){
11            int val=8;
12            int ans=1;
13            for(int k=1;k<=i-2;k++){
14                ans*=val;
15                val--;
16            }
17            dp[i]=dp[i-1]+(ans*81);
18       }
19
20       return dp[n];
21    }
22};
23
24
25
26
27
28