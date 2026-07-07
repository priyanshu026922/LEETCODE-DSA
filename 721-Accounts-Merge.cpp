class DisjointSet{
   private:
     vector<int>size;
   public:
     vector<int>par;

    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);

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

   void unionBySize(int u,int v){
    int ulp_u=findPar(u);
    int ulp_v=findPar(v);
     
     if(ulp_u==ulp_v){
          return;
     }

     if(size[ulp_u]>size[ulp_v]){
        size[ulp_u]+=size[ulp_v];
        par[ulp_v]=ulp_u;
     }else{
          size[ulp_v]+=size[ulp_u];
          par[ulp_u]=ulp_v;
     }
     
   }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
          
          int n=accounts.size();
          
          DisjointSet ds(n);
          unordered_map<string,int>mp;

          for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string x=accounts[i][j];
                if(mp.find(x)==mp.end()){
                    mp[x]=i;
                }else{
                    ds.unionBySize(mp[x],i);
                }
            }
          }

          vector<vector<string>>ans(n);

          for(auto it:mp){

            string x=it.first;
            
                 int val=ds.findPar(it.second);

                 ans[val].push_back(x);

          }

            vector<vector<string>>res;


            for(int i=0;i<ans.size();i++){
                if(ans[i].size()==0)continue;
                vector<string>a;

                a.push_back(accounts[i][0]);
                for(int j=0;j<ans[i].size();j++){
                   a.push_back(ans[i][j]);
                }
                sort(begin(a)+1,end(a));
                res.push_back(a);
            }


        return res;
          
    }
};