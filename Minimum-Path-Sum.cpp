1class Solution {
2public:
3int n,m;
4typedef long long  ll;
5    int minPathSum(vector<vector<int>>& grid) {
6        n=grid.size();
7        m=grid[0].size();
8        
9        //SPACE COMPLEXITY :o(N*M);--->possibilty that whether it can be optimsed to O(m) or O(n)--
10
11        // for(int i=0;i<201;i++){
12        //     for(int j=0;j<201;j++){
13        //         dp[i][j]=0;
14        //     }
15        // }
16    
17    //    dp[n-1][m-1]=grid[n-1][m-1];
18       
19       vector<int>nxt(m,INT_MAX);
20      
21        for(int i=n-1;i>=0;i--){
22            vector<int>curr(m,INT_MAX);///---->what this does is that this store minmumu value in the curr state
23            for(int j=m-1;j>=0;j--){
24                if(i==n-1&&j==m-1){
25                    curr[j]=grid[n-1][m-1];
26                    continue;
27                }
28
29                ll l=INT_MAX;
30
31                 if(j+1<m)  l=1LL*grid[i][j]+curr[j+1];//in the next state ,look for the jth index-->nxt state
32                 ll r=1LL*grid[i][j]+nxt[j];//in the same state i look for j+1 th state--->curr
33                 
34                curr[j]=min(l,r);
35               
36            }
37            nxt=curr;
38        }
39
40        return (int)nxt[0];
41    }
42};