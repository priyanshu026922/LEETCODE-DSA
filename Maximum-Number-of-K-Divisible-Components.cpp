1class Solution {
2public:
3    int solve(vector<vector<int>>&adj,int node,vector<int>& values,int k,int &cnt,vector<int>&vis){
4        
5        vis[node]=1;
6        
7        int sum=values[node];
8        for(auto it:adj[node]){
9             if(!vis[it]){
10                 sum+=solve(adj,it,values,k,cnt,vis);
11                 sum%=k;
12             }
13        }
14        sum=sum%k;
15        if(sum==0){
16            cnt++;
17        }
18         return sum;
19    }
20    int maxKDivisibleComponents(int n, vector<vector<int>>&edges, vector<int>& values, int k) {
21          vector<vector<int>>adj(n);
22          for(auto it:edges){
23            int u=it[0];
24            int v=it[1];
25            adj[u].push_back(v);
26            adj[v].push_back(u);
27          }
28
29          vector<int>vis(n,0);
30
31            int cnt=0;
32            solve(adj,0,values,k,cnt,vis);
33            return cnt;
34    }
35};