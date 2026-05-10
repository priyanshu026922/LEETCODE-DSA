1class Solution {
2public:
3 typedef long long ll;
4    typedef pair<int,ll> pii;
5    typedef pair<int,pii> piii;
6   
7
8    vector<ll> getShortestPaths(int n, vector<vector<piii>> &adj,
9                                int source, bool simple) {
10
11        vector<ll> dist(n, 1e18);
12        dist[source] = 0;
13
14        priority_queue<pair<ll,int>,
15                       vector<pair<ll,int>>,
16                       greater<pair<ll,int>>> pq;
17
18        pq.push({0, source});
19
20        while (!pq.empty()) {
21
22            auto [du, u] = pq.top();
23            pq.pop();
24
25            if (du != dist[u])
26                continue;
27
28            for (auto &e : adj[u]) {
29
30                int v = e.first;
31
32                ll len = (simple ? e.second.first
33                                 : e.second.second);
34
35                if (dist[u] + len < dist[v]) {
36
37                    dist[v] = dist[u] + len;
38
39                    pq.push({dist[v], v});
40                }
41            }
42        }
43
44        return dist;
45    }
46
47    vector<int> minCost(int n,
48                        vector<int>& prices,
49                        vector<vector<int>>& roads) {
50
51        vector<int> ans(n,0);
52
53        vector<vector<piii>> adj(n);
54
55        for(auto &it : roads){
56
57            int u = it[0];
58            int v = it[1];
59            int cost = it[2];
60            int tax = it[3];
61
62            adj[u].push_back({v,{cost,1LL*cost*tax}});
63            adj[v].push_back({u,{cost,1LL*cost*tax}});
64        }
65
66        for(int i=0;i<n;i++){
67
68            vector<ll> simple =
69                getShortestPaths(n, adj, i, true);
70
71            vector<ll> taxed =
72                getShortestPaths(n, adj, i, false);
73
74            ll mini = prices[i];
75
76            for(int k=0;k<n;k++){
77
78                if(k!=i){
79
80                    mini = min(mini,
81                               simple[k]
82                               + prices[k]
83                               + taxed[k]);
84                }
85            }
86
87            ans[i] = mini;
88        }
89
90        return ans;
91    }
92};