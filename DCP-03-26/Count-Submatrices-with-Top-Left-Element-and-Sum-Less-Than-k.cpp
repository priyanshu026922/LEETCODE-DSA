1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int n=grid.size();
5        int m=grid[0].size();
6        
7        vector<vector<int>>pref(n,vector<int>(m,0));
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10              pref[i][j]=grid[i][j]+(j>0?pref[i][j-1]:0)+(i>0?pref[i-1][j]:0)-(i>0&&j>0?pref[i-1][j-1]:0);
11            }
12        }
13        int cnt=0;
14        for(int i=0;i<n;i++){
15            for(int j=0;j<m;j++){
16                if(pref[i][j]<=k){
17                    cnt++;
18                }
19            }
20        }
21        return cnt;
22    }
23};