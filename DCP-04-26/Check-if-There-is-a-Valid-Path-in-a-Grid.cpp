1class Solution {
2public:
3int n,m;
4    unordered_map<int,vector<vector<int>>>dir={
5        {1,{{0,-1},{0,1}}},
6        {2,{{-1,0},{1,0}}},
7        {3,{{0,-1},{1,0}}},
8        {4,{{0,1},{1,0}}},
9        {5,{{0,-1},{-1,0}}},
10        {6,{{-1,0},{0,1}}},
11    };
12
13    bool solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&vis){
14        if(i==n-1&&j==m-1)return true;
15
16        vis[i][j]=1;
17
18        for(auto &it:dir[grid[i][j]]){
19            int new_i=i+it[0];
20            int new_j=j+it[1];
21            if(new_i<0||new_i>=n||new_j<0||new_j>=m||vis[new_i][new_j]==1)continue;
22            
23            //can we come back from to i and j from new_i &new_j
24            for(auto &Dir:dir[grid[new_i][new_j]]){
25                if(new_i+Dir[0]==i&&new_j+Dir[1]==j){
26                    if(solve(new_i,new_j,grid,vis)){
27                        return true;
28                    }
29                }
30            }
31        }
32        return false;
33    }
34
35    bool hasValidPath(vector<vector<int>>& grid) {
36         n=grid.size();
37         m=grid[0].size();
38         vector<vector<int>>vis(n,vector<int>(m,0));
39         return  solve(0,0,grid,vis);
40    }
41};