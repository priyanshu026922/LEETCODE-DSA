1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int cnt=0;
7        for(int i=0;i<n;i++){
8            for(int j=0;j<m;j++){
9              grid[i][j]=grid[i][j]+(j>0?grid[i][j-1]:0)+(i>0?grid[i-1][j]:0)-(i>0&&j>0?grid[i-1][j-1]:0);
10              if(grid[i][j]<=k){
11                    cnt++;
12                }
13            }
14        } 
15        return cnt;
16    }
17};