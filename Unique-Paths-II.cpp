1class Solution {
2public:
3    int n,m;
4    typedef long long ll;
5    int uniquePathsWithObstacles(vector<vector<int>>& o) {
6        n=o.size();
7        m=o[0].size();
8        // vector<vector<ll>>dp(n,vector<ll>(m,0));
9        
10        
11        if(o[0][0]==1||o[n-1][m-1]==1){
12              return 0;
13        }
14         
15         vector<ll>dp(m,0);
16        //can we fall down the S.C TO O(N):
17        //
18        dp[m-1]=1;
19        for(int i=n-1;i>=0;i--){
20            for(int j=m-1;j>=0;j--){
21                 if(i==n-1&&j==m-1)continue;
22                  
23                 if(o[i][j]){
24                    dp[j]=0;
25                    continue;
26                 }
27
28                 ll l=0;
29                 ll r=0;
30                 if(j+1<m)l=dp[j+1];
31                 if(i+1<n)r=dp[j];
32
33                  dp[j]=(l+r);
34            }
35        }
36        return (int)dp[0];
37        
38    }
39};