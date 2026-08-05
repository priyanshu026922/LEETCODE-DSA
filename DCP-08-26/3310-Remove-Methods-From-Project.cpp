class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,int n,vector<int>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(vis[it]==0){
                dfs(adj,it,n,vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &it:invocations){
             int x=it[0];
             int y=it[1];
             adj[x].push_back(y);
        }

        //k is a bug
        //remove all the  commonents that origin from this node
        //but also dont have 
        vector<int>vis(n,0);
        dfs(adj,k,n,vis);
vector<int>ans;
        //this will mark all the nodes which will be reachable by node k direclty or indireclty
        
        //check rkna hai kya kisi unvisited node se reachable hai kya yeh sab visted nodes
        //now we check if nodes not vivisted 
        bool t=false;
        for(auto &it:invocations){
             int x=it[0];
             int y=it[1];
             if(vis[x]==0&&vis[y]==1){
                t=true;
                break;
             }
        }

        if(t==true){
            for(int i=0;i<n;i++){
               ans.push_back(i);
            }
            return ans;
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};