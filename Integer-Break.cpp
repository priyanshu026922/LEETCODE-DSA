1class Solution {
2public:
3    int integerBreak(int n) {
4      vector<int>dp(n+1,1);
5      if(n==2){
6         return 1;
7      }
8      if(n==3){
9         return 2;
10      }
11      if(n==4){
12         return 4;
13      }
14      if(n==5){
15         return 6;
16      }
17      if(n==6){
18        return 9;
19      }
20      dp[2]=1;
21      dp[3]=2;
22      dp[4]=4;
23      dp[5]=6;
24      dp[6]=9;
25      for(int i=7;i<=n;i++){
26        if(i%3==0){
27            dp[i]=dp[i-1]/2*3;
28        }
29        if(i%3==1){
30             dp[i]=dp[i-1]/3*4;
31        }
32        if(i%3==2){
33            dp[i]=dp[i-2]*2;
34        }
35      }
36      return dp[n];
37    }
38};