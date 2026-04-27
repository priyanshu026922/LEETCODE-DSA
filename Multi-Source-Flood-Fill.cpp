1class Solution {
2public:
3   int drow[4]={-1,0,1,0};
4   int dcol[4]={0,-1,0,1};
5    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
6
7        vector<vector<pair<int,int>>>vis(n,vector<pair<int,int>>(m,{0,INT_MAX}));//{store the color+its min time}
8
9        queue<pair<pair<int,int>,int>>q;//{{i,j},time};
10        for(auto &it:sources){
11            int i=it[0];
12            int j=it[1];
13            int color=it[2];
14
15            q.push({{i,j},0});//{i,j,time}
16            vis[i][j]={color,0};//{color,time}
17        }
18
19        while(!q.empty()){
20            int i=q.front().first.first;
21            int j=q.front().first.second;
22
23            int t=q.front().second;
24            q.pop();
25
26            for(int k=0;k<4;k++){
27                int new_i=drow[k]+i;
28                int new_j=dcol[k]+j;
29
30                if(new_i<0||new_i>=n||new_j<0||new_j>=m){
31                     continue;
32                }
33
34                // if(vis[new_i][new_j].second!=INT_MAX){
35
36                    if(t+1<vis[new_i][new_j].second){
37                        vis[new_i][new_j]={vis[i][j].first,t+1};
38                        q.push({{new_i,new_j},vis[new_i][new_j].second});
39                    }
40                   
41                    if(t+1==vis[new_i][new_j].second){
42                        int maxi=max(vis[i][j].first,vis[new_i][new_j].first);
43                        vis[new_i][new_j]={maxi,t+1};
44                    }
45
46                 
47
48            }
49        }
50
51
52        vector<vector<int>>ans(n,vector<int>(m,0));
53        for(int i=0;i<n;i++){
54            for(int j=0;j<m;j++){
55                ans[i][j]=vis[i][j].first;
56            }
57        }
58        return ans;
59
60    }
61};