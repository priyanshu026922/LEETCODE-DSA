1class Solution {
2public:
3int mod=1e9+7;
4 int dp[1002][1002][3];//zero,one,last
5    int numberOfStableArrays(int zero, int one, int limit) {
6        for(int i=0;i<=min(zero,limit);i++){
7            dp[i][0][0]=1;//one-zero
8        }
9
10        for(int i=0;i<=min(one,limit);i++){
11            dp[0][i][1]=1;
12        }
13
14        for(int z=0;z<=zero;z++){
15            for(int o=0;o<=one;o++){
16                if(o==0||z==0)continue;
17               dp[z][o][1]=(dp[z][o-1][1]+dp[z][o-1][0])%mod;
18               if(o>limit) dp[z][o][1]=(dp[z][o][1]-dp[z][o-limit-1][0]+mod)%mod;
19               dp[z][o][0]=(dp[z-1][o][1]+dp[z-1][o][0])%mod;
20               if(z>limit) dp[z][o][0]=(dp[z][o][0]-dp[z-1-limit][o][1]+mod)%mod;
21            }
22        }
23        
24        int a1=dp[zero][one][1];
25        int a2=dp[zero][one][0];
26        return (a1+a2)%mod;
27    }
28};