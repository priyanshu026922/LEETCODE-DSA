1class Solution {
2public:
3int n,m;
4
5//    int solve(int i,int j1,int j2,vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
6
7//     if(j1<0||j2<0||j1>=m||j2>=m){
8//         return INT_MIN;
9//     }
10
11//         if(i==n-1){
12//             if(j1==j2){
13//                 return grid[n-1][j1];
14//             }else{
15//                 return grid[n-1][j1]+grid[n-1][j2];
16//             }
17//         }
18
19//         if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
20
21//         int maxi=INT_MIN;
22//         for(int x=-1;x<=1;x++){
23//             for(int y=-1;y<=1;y++){
24//                 int val=0;
25
26//               if(j1==j2){
27//                   val+=grid[i][j1];
28//               }else{
29//                   val=grid[i][j1]+grid[i][j2];
30//               }
31
32//              val=val+solve(i+1,j1+x,j2+y,grid,dp);
33//              maxi=max(maxi,val);
34//             }
35//         }
36//         return  dp[i][j1][j2]=maxi;
37//    }
38    int cherryPickup(vector<vector<int>>& grid) {
39        //we have 3 directions to go
40        //{-1,0,1};
41        n=grid.size();
42        m=grid[0].size();
43        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
44
45        vector<vector<int>>nxt(m,vector<int>(m,0));
46
47        //BASE CASE COVERED
48         for(int j1=0;j1<m;j1++){
49            for(int j2=0;j2<m;j2++){
50                if(j1==j2){
51                   nxt[j1][j2]=grid[n-1][j1];
52                }else{
53                   nxt[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
54                }
55            }
56         }
57
58        for(int i=n-2;i>=0;i--){
59            vector<vector<int>>curr(m,vector<int>(m,0));
60
61            for(int j1=0;j1<m;j1++){
62                for(int j2=0;j2<m;j2++){
63                   int maxi=INT_MIN;
64
65                    for(int x=-1;x<=1;x++){
66                        for(int y=-1;y<=1;y++){
67                            int val=0;
68
69                        if(j1==j2){
70                            val=grid[i][j1];
71                        }else{
72                            val=grid[i][j1]+grid[i][j2];
73                        }
74                        
75                        if(j1+x>=0&&j2+y>=0&&j1+x<m&&j2+y<m) val=val+nxt[j1+x][j2+y];
76
77                        maxi=max(maxi,val);
78                        }
79                    }
80
81                    curr[j1][j2]=maxi;
82
83                }
84            }
85            nxt=curr;
86        }
87        return nxt[0][m-1];
88    }
89};