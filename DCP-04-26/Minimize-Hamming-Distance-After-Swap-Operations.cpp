1class DisjointSet{
2   vector<int>parent,rank;
3
4    public:
5
6    DisjointSet(int n){
7        rank.resize(n+1,0);
8        parent.resize(n+1);
9        for(int i=0;i<=n;i++){
10            parent[i]=i;
11        }
12    }
13
14    int findPar(int node){
15        if(node==parent[node]){
16            return node;
17        }
18        return parent[node]=findPar(parent[node]);
19    }
20    
21    void UnionByRank(int u,int v){
22        int p_u=findPar(u);
23        int p_v=findPar(v);
24        if(p_u==p_v)return;
25
26        if(rank[p_u]>rank[p_v]){
27             parent[p_v]=p_u;
28        }
29        else if(rank[p_u]<rank[p_v]){
30            parent[p_u]=p_v;
31        }else{
32            parent[p_u]=p_v;
33            rank[p_v]++;
34        }
35    }
36
37};
38
39class Solution {
40public:
41    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
42        int n=source.size();
43
44        DisjointSet ds(n);
45        for(auto &vec:allowedSwaps){
46            int x=vec[0];
47            int y=vec[1];
48            ds.UnionByRank(x,y);
49        }
50
51        unordered_map<int,unordered_map<int,int>>grpFreq;
52        
53        for(int i=0;i<n;i++){
54            int curr=source[i];
55            int par=ds.findPar(i);
56            grpFreq[par][curr]++;
57        }
58        
59        int cnt=0;
60        for(int i=0;i<n;i++){
61            int par=ds.findPar(i);
62            if(grpFreq[par][target[i]]>0){
63                grpFreq[par][target[i]]--;
64            }else{
65                cnt++;
66            }
67        }
68        return cnt;
69    }
70};