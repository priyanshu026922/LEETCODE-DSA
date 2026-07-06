class DisjointSet{
   private:
     vector<int>size;
   public:
     vector<int>par;
     vector<int>min_score;

    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        min_score.resize(n+1,INT_MAX);

        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }

   int findPar(int node){
        if(par[node]==node){
            return node;
        }
        return par[node]=findPar(par[node]);
   }

   void unionBySize(int u,int v,int wt){
    int ulp_u=findPar(u);
    int ulp_v=findPar(v);
     
     min_score[ulp_u]=min(min_score[ulp_u],wt);
     min_score[ulp_v]=min(min_score[ulp_v],wt);
     if(ulp_u==ulp_v){
          return;
     }

     if(size[ulp_u]>size[ulp_v]){
        size[ulp_u]+=size[ulp_v];
         min_score[ulp_u]=min(min_score[ulp_u],min_score[ulp_v]);
        par[ulp_v]=ulp_u;
     }else{
          size[ulp_v]+=size[ulp_u];
          par[ulp_u]=ulp_v;
           min_score[ulp_v]=min(min_score[ulp_v], min_score[ulp_u]);
     }
     
   }
};


class Solution {
public:
   
    int minScore(int n, vector<vector<int>>& roads) {
       DisjointSet ds(n);
       
       for(auto &it:roads){
            int x=it[0]-1;
            int y=it[1]-1;
            int z=it[2];
            
            ds.unionBySize(x,y,z);
        }

        int par1=ds.findPar(0);
        int par2=ds.findPar(n-1);

        cout<<par1<<" ::"<<par1<<endl;

        
        int val=ds.min_score[par1];
        cout<<val<<endl;

        return val;
    }
};