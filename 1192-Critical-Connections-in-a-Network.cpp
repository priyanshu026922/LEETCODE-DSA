class Solution {
public:
    int timer=1;
    void solve(int node,int par,int n,vector<vector<int>>&adj,vector<vector<int>>&ans,  vector<int>&low,vector<int>&time,vector<int>&vis){
        vis[node]=1;
        low[node]=time[node]=timer;
        timer++;
        for(auto &it:adj[node]){
            if(it==par)continue;

            if(vis[it]==0){
                 solve(it,node,n,adj,ans,low,time,vis);

                 low[node]=min(low[node],low[it]);

                 if(low[it]>time[node]){
                    ans.push_back({node,it});
                 }
            }else{
                 low[node]=min(low[node],low[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(auto &it:connections){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int>vis(n,0);
        vector<int>low(n,0);
        vector<int>time(n,0);
        solve(0,-1,n,adj,ans,low,time,vis);
        return ans;
        
    }
};