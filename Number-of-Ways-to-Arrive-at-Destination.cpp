1class Solution {
2public:
3    int mod=1e9+7;
4    typedef long long ll;
5    typedef pair<ll,ll> pii;
6    int countPaths(int n, vector<vector<int>>& roads) {
7        vector<vector<pair<int,int>>>adj(n);
8
9        for(auto &it:roads){
10            int x=it[0];
11            int y=it[1];
12            int wt=it[2];
13
14            adj[x].push_back({y,wt});
15            adj[y].push_back({x,wt});
16        }
17
18        vector<ll>ways(n,0);
19        ways[0]=1;
20        vector<ll>dis(n,1e12);
21        dis[0]=0;
22        priority_queue<pii,vector<pii>,greater<pii>>pq;
23        pq.push({0,0});
24        while(!pq.empty()){
25            ll wt=pq.top().first;
26            ll node=pq.top().second;
27            
28            pq.pop();
29            for(auto it:adj[node]){
30                ll neighbour=it.first;
31                ll w=it.second;
32
33                if(wt+w<dis[neighbour]){
34                    dis[neighbour]=wt+w;
35                    ways[neighbour]=ways[node];
36                    pq.push({dis[neighbour],neighbour});
37                }
38                else if(wt+w==dis[neighbour]){
39                    //  pq.push({dis[neighbour],neighbour});
40                     ways[neighbour]=(ways[neighbour]+ways[node])%mod;
41                }
42            }
43        }
44
45        return ways[n-1];
46    }
47};