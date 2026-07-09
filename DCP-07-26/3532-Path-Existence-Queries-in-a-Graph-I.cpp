class DSU{
    public:
    vector<int>par;
    vector<int>size;

    DSU(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }

    int findP(int node){
        if(par[node]==node){
            return node;
        }

        return par[node]=findP(par[node]);
    }


    void UnionBySize(int u,int v){
          int ulp_u=findP(u);
          int ulp_v=findP(v);

          if(ulp_u==ulp_v)return;

          if(size[ulp_u]>size[ulp_v]){
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
          }else{
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
          }
    }


};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;

        DSU ds(n);

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
               ds.UnionBySize(i,i-1);
            }
        }

        for(auto it:queries){
            int x=it[0];
            int y=it[1];

            if(ds.findP(x)==ds.findP(y)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};