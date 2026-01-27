1class Solution {
2public:
3    int minCost(int n, vector<vector<int>>& edges) {
4        vector<vector<pair<int,int>>>adj(n);
5        for(auto it:edges){
6            int x=it[0];
7            int y=it[1];
8            int z=it[2];
9            adj[x].push_back({y,z});
10              adj[y].push_back({x,2*z});
11        }
12
13        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
14        pq.push({0,0});
15        vector<int>vis(n,0);
16        vector<int>dis(n,1e9);
17        dis[0]=0; 
18        while(!pq.empty()){
19           int wt=pq.top().first;
20           int node=pq.top().second;
21           pq.pop();
22
23           for(auto it:adj[node]){
24              int u=it.first;
25              int d=it.second;
26            // if(dis[u]+2*d<dis[node]&&!vis[u]){
27            //         dis[node]=dis[u]+2*d;
28            //         vis[u]=1;
29            //     pq.push({dis[node],node});
30            // }
31            // else
32             if(wt+d<dis[u]){
33                  dis[u]=wt+d;
34                  pq.push({dis[u],u});
35            }
36
37           }
38        }
39        if(dis[n-1]==1e9)return -1;
40        return dis[n-1];
41    }
42};