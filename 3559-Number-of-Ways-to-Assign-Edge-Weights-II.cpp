class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int col;
     vector<vector<int>>ancestor;
    //DONE
    void dfs(int node,int par, int depth,vector<vector<int>>&ancestor,vector<int>&h,vector<int>&vis,vector<vector<int>>&adj){
        h[node]=depth;
        vis[node]=1;
        ancestor[node][0]=par;
        for(auto &it:adj[node]){
            int neighbour=it;
            if(neighbour!=par){
              dfs(neighbour,node,depth+1,ancestor,h,vis,adj);
            }
        }

    }
    
    //DONE
    int jump(int x,int dis, vector<vector<int>>&ancestor){

        for(int i=0;i<32;i++){
            if(dis&(1<<i)){
                x=ancestor[x][i];
            }

            if(x==-1){
                return -1;
            }
        }

        return x;
    }
    
    //done
    ll s(ll val){
         ll res=1;
         ll x=2;
         int n=val-1;

         if(n<0){
            return 0;
         }
         while(n>0){
            if(n%2!=0){
                res=(res*x)%mod;
            }

            x=(x*x)%mod;
            n/=2;
         }
         
        //  if(val%2==0){
        //     return (res+1)%mod;
        //  }

         return res;
    }


    ll getJump(int u,int v,vector<int>&depth){
          
           if(depth[u]<depth[v]) swap(u,v);

            u=jump(u,depth[u]-depth[v],ancestor);

            if(u==v) return u;

            for(int i=col-1;i>=0;i--){
                if(ancestor[u][i]!=ancestor[v][i]){
                    u=ancestor[u][i];
                    v=ancestor[v][i];
                }
            }

            return ancestor[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        

        col=log2(n)+1;
        //DONE
        for(auto &it:edges){
            int x=it[0]-1;
            int y=it[1]-1;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }


       ancestor.assign(n,vector<int>(log2(n)+1,-1));
        vector<int>height(n,0);
        vector<int>vis(n,0);
        dfs(0,-1,0,ancestor,height,vis,adj);

        for(int j=1;j<=log2(n);j++){
            for(int i=0;i<=n-1;i++){
               if(ancestor[i][j-1]!=-1) ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
            }
        }

        vector<int>ans;
        for(auto &it:queries){
            int x=it[0]-1;
            int y=it[1]-1;
            
           int h1=height[x];
           int h2=height[y];


           int lca=getJump(x,y,height);//---->solving this
            
           int dist = height[x] + height[y] - 2 * height[lca];
           int a=s(dist);//cal power of 2^(n-1 )

           ans.push_back(a);
            
        }

        return ans;
    }
};