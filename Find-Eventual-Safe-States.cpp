1class Solution {
2public:
3    bool dfs(int node,vector<vector<int>>&adj, vector<int>&vis,vector<int>&prevVis, vector<int>&isPos){
4        vis[node]=1;
5        prevVis[node]=1;
6        for(auto it:adj[node]){
7            if(!vis[it]){
8                if(dfs(it,adj,vis,prevVis,isPos)){
9                    isPos[node]=0;
10                    return true;
11                }
12            }else if(vis[it]&&prevVis[it]){
13                   isPos[node]=0;
14                   return true;
15            }
16        }
17        
18        prevVis[node]=0;
19        isPos[node]=1;
20        return false;
21    }
22
23    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
24        int n=graph.size();
25        vector<int>vis(n,0);
26        vector<int>prevVis(n,0);
27        vector<int>isPos(n,0);
28        for(int i=0;i<n;i++){
29            if(!vis[i]){
30                dfs(i,graph,vis,prevVis,isPos);
31            }
32        }
33        vector<int>ans;
34        for(int i=0;i<n;i++){
35            if(isPos[i]){
36                ans.push_back(i);
37            }
38        }
39        return ans;
40    }
41};