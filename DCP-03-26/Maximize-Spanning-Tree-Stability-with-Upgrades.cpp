1class DisjointSet{
2    vector<int>rank,parent;
3    public:
4    DisjointSet(int n){
5        rank.resize(n+1,0);
6        parent.resize(n+1);
7        for(int i=0;i<n;i++){
8            parent[i]=i;
9        }
10    }
11
12    int findPar(int node){
13        if(node==parent[node]){
14            return node;
15        }
16        return parent[node]=findPar(parent[node]);
17    }
18
19    void unionByRank(int u,int v){
20        int ulp_u=findPar(u);
21        int ulp_v=findPar(v);
22        if(ulp_v==ulp_u)return;
23        if(rank[ulp_u]<rank[ulp_v]){
24            parent[ulp_u]=ulp_v;
25        }else if(rank[ulp_u]>rank[ulp_v]){
26            parent[ulp_v]=ulp_u;
27        }else{
28            parent[ulp_v]=ulp_u;
29            rank[ulp_u]++;
30        }
31    }
32};
33
34
35class Solution {
36public:
37
38bool check(vector<vector<int>>& edges, int k,int n,int mid){
39        DisjointSet ds(n);
40        vector<vector<int>>upgrade;
41        for(auto &it:edges){
42            int x=it[0];
43            int y=it[1];
44            int z=it[2];
45            int t=it[3];
46            if(t==1){
47                if(z<mid){
48                    return false;
49                }
50
51                ds.unionByRank(x,y);
52                
53            }else{
54                if(z>=mid){
55                   ds.unionByRank(x,y);
56                }else if(z*2>=mid){
57                    upgrade.push_back({x,y});
58                }
59            }
60        }
61
62        for(auto it:upgrade){
63            int u=it[0];
64            int v=it[1];
65            if(ds.findPar(u)!=ds.findPar(v)){
66                if(k<=0){
67                    return false;
68                }
69                ds.unionByRank(u,v);
70                k--;
71            }
72        }
73        int root=ds.findPar(0);
74        for(int i=0;i<n;i++){
75            if(ds.findPar(i)!=root){
76                return false;
77            }
78        }
79        return true;
80}
81
82    int maxStability(int n, vector<vector<int>>& edges, int k) {
83       DisjointSet ds(n);
84        
85        for(auto &it:edges){
86            int x=it[0];
87            int y=it[1];
88            int z=it[2];
89            int t=it[3];
90            if(t==1){
91                if(ds.findPar(x)==ds.findPar(y)){
92                    return -1;
93                }
94                ds.unionByRank(x,y);
95            }
96        }
97
98       int l=0,r=2*1e5;
99       int ans=-1;
100        while(l<=r){
101            int mid=(l+r)/2;
102            bool x=check(edges,k,n,mid);
103            if(x){
104                ans=mid;
105                l=mid+1;
106            }else{
107                r=mid-1;
108            }
109        }
110        return ans;
111    }
112};