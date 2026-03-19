1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int cnt=0;
7        vector<vector<pair<int,int>>>ans(n,vector<pair<int,int>>(m,{0,0}));
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                if(grid[i][j]=='X')ans[i][j].first++;
11                else if(grid[i][j]=='Y')ans[i][j].second++;
12                 
13                 if(j>0){
14                    ans[i][j].first+=ans[i][j-1].first;
15                    ans[i][j].second+=ans[i][j-1].second;
16                 }
17                  if(i>0){
18                    ans[i][j].first+=ans[i-1][j].first;
19                    ans[i][j].second+=ans[i-1][j].second;
20                 }
21                 if(i>0&&j>0){
22                     ans[i][j].first-=ans[i-1][j-1].first;
23                     ans[i][j].second-=ans[i-1][j-1].second;
24                 }
25                   if(ans[i][j].first==ans[i][j].second&&ans[i][j].first>0){
26                           cnt++;
27                   }
28            }
29
30        }
31        return cnt;
32    }
33};