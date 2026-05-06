1class Solution {
2public:
3typedef pair<int,pair<int,int>> piii;
4    int drow[8]={-1,-1,0,1,1,1,0,-1};
5    int dcol[8]={0,-1,-1,-1,0,1,1,1};
6    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
7        if(grid[0][0]!=0)return -1;
8        int n=grid.size();
9        int m=grid[0].size();
10        vector<vector<int>>dis(n,vector<int>(m,1e9));
11        
12        dis[0][0]=1;
13        priority_queue<piii,vector<piii>,greater<piii>>pq;
14        pq.push({1,{0,0}});
15        while(!pq.empty()){
16            int wt=pq.top().first;
17            int i=pq.top().second.first;
18            int j=pq.top().second.second;
19            
20            pq.pop();
21            for(int k=0;k<8;k++){
22                int new_i=i+drow[k];
23                int new_j=j+dcol[k];
24
25                if(new_i<0||new_j<0||new_i>=n||new_j>=m||grid[new_i][new_j]!=0){
26                    continue;
27                }
28                if(dis[i][j]+1<dis[new_i][new_j]){
29                    dis[new_i][new_j]=1+dis[i][j];
30                    pq.push({ dis[new_i][new_j],{new_i,new_j}});
31                }
32            }
33        }
34        return dis[n-1][n-1]==1e9?-1:dis[n-1][n-1];
35    }
36};