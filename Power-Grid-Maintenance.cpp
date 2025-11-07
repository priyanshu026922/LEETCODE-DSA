class Solution {
public:

void dfs(int node, vector<vector<int>>&adj, int id, vector<int>&nodeId,  unordered_map<int,set<int>>&mp,vector<int>&vis){
     vis[node]=1;
     mp[id].insert(node);
     nodeId[node]=id;
     for(int &it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,id,nodeId,mp,vis);
        }
     }
} 

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<vector<int>> adj(c + 1);

        for (auto &it : connections) {
            int x = it[0];
            int y = it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
            
       
        vector<int>vis(c+1,0);
        vector<int>nodeId(c+1);

        unordered_map<int,set<int>>mp;

        for(int node=1;node<=c;node++){
           if(!vis[node]){
             int id=node;
             dfs(node,adj,id,nodeId,mp,vis);
           }
        }
        
        for(auto &q:queries){
            int type=q[0];
            int node=q[1];
            if(type==1){
                int id=nodeId[node];
                 if(mp[id].count(node)){
                    ans.push_back(node);
                 }else if(!mp[id].empty()){
                    ans.push_back(*mp[id].begin());
                 }else{
                    ans.push_back(-1);
                 }
            }else{
                int id=nodeId[node];
                mp[id].erase(node);
            }
        }
     

     return ans;


    }
};