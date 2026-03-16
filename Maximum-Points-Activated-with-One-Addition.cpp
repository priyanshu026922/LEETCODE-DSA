1class DisjointSet{
2    public:
3    vector<int>parent;
4    vector<int>size;
5    DisjointSet(int n){
6        size.resize(n+1,1);
7        parent.resize(n+1);
8        for(int i=0;i<=n;i++){
9            parent[i]=i;
10        }
11    }
12
13    int findP(int node){
14        if(node==parent[node])return node;
15        return parent[node]=findP(parent[node]);
16    }
17    void UnionBySize(int u,int v){
18        int ulp_u=findP(u);
19        int ulp_v=findP(v);
20        if(ulp_u==ulp_v)return ;
21        if(size[ulp_u]>size[ulp_v]){
22            parent[ulp_v]=ulp_u;
23            size[ulp_u]+=size[ulp_v];
24        }else{
25              parent[ulp_u] = ulp_v;
26              size[ulp_v]+=size[ulp_u];
27        }
28    }
29};
30
31class Solution {
32public:
33    int maxActivated(vector<vector<int>>& points) {
34        int n=points.size();
35        DisjointSet ds(n);
36        map<int,vector<int>>x,y;
37        for(int i=0;i<n;i++){
38            x[points[i][0]].push_back(i);
39            y[points[i][1]].push_back(i);
40        }
41
42        for(auto it:x){
43            for(int j=0;j<it.second.size()-1;j++){
44                ds.UnionBySize(it.second[j],it.second[j+1]);
45            }
46        }
47
48        for(auto it:y){
49            for(int j=0;j<it.second.size()-1;j++){
50                ds.UnionBySize(it.second[j],it.second[j+1]);
51            }
52        }
53        map<int,int>mp;
54        for(int i=0;i<n;i++){
55            int r=ds.findP(i);
56            mp[r]++;
57        }
58        vector<int>v;
59        for(auto it:mp){
60            v.push_back(it.second);
61        }
62        sort(begin(v),end(v));
63        if(v.size()==1){
64            return v[0]+1;
65            
66        }
67        return v[v.size()-1]+v[v.size()-2]+1;
68
69    }
70};