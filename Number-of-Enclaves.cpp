1class Solution {
2public:
3int drow[4]={-1,0,1,0};
4int dcol[4]={0,-1,0,1};
5  int n,m;
6    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j){
7         vis[i][j]=1;
8         for(int k=0;k<4;k++){
9            int new_i=drow[k]+i;
10            int new_j=dcol[k]+j;
11
12            if(new_i<0||new_i>=n||new_j<0||new_j>=m)continue;
13            if(vis[new_i][new_j]==0&&grid[new_i][new_j]==1){
14                dfs(grid,vis,new_i,new_j);
15            }
16         }
17    }
18
19    int numEnclaves(vector<vector<int>>& grid) {
20        n=grid.size();
21        m=grid[0].size();
22        vector<vector<int>>vis(n,vector<int>(m,0));
23        for(int i=0;i<n;i++){
24            if(grid[i][0]==1){
25                dfs(grid,vis,i,0);
26            }
27        }
28
29         for(int i=0;i<n;i++){
30            if(grid[i][m-1]==1){
31                dfs(grid,vis,i,m-1);
32            }
33        }
34         for(int i=0;i<m;i++){
35            if(grid[0][i]==1){
36                dfs(grid,vis,0,i);
37            }
38        }
39         for(int i=0;i<m;i++){
40            if(grid[n-1][i]==1){
41                dfs(grid,vis,n-1,i);
42            }
43        }
44        
45        int cnt=0;
46        for(int i=0;i<n;i++){
47            for(int j=0;j<m;j++){
48                if(grid[i][j]==1&&vis[i][j]==0)cnt++;
49            }
50        }
51        return cnt;
52
53    }
54};