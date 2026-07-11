class DSU{
   public:
    vector<int>par;
    vector<int>size;
    vector<int>edges;

    DSU(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        edges.resize(n+1,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findP(int u){
        if(par[u]==u){
            return u;
        }

        return par[u]=findP(par[u]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findP(u);
        int ulp_v=findP(v);

        if(ulp_v==ulp_u){
            edges[ulp_u]++;
            return;
        }


        if(size[u]>size[v]){
            size[ulp_u]+=size[ulp_v];
            par[ulp_v]=ulp_u;
            edges[ulp_u]+=(edges[ulp_v]+1);
        }else{
           size[ulp_v]+=size[ulp_u];
           par[ulp_u]=ulp_v;
           edges[ulp_v]+=(edges[ulp_u]+1);
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        DSU ds(n);

        for(auto &it:edges){
            int x=it[0];
            int y=it[1];

            ds.unionBySize(x,y);
        }

        int cnt=0;
 
        for(int i=0;i<n;i++){
            int par=ds.findP(i);
            if(par==i){
               int s=ds.size[i];
               int e=ds.edges[i];
                
               
               int m=s*(s-1)/2;

               if(e==m){
                cnt++;
               }
            //    if(s==e){
            //      cnt++;
            //    }
            }
        }

        return cnt;
    }
};