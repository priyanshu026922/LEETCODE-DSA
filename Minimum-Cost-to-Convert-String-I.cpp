1class Solution {
2public:
3typedef long long ll;
4    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
5          ll ans=0;
6
7        vector<vector<ll>>adj(26,vector<ll>(26,LLONG_MAX));
8
9       for(int i = 0; i < 26; i++) adj[i][i] = 0;
10
11      for(int i=0;i<original.size();i++){
12        int s=original[i]-'a';
13        int t=changed[i]-'a';
14
15        adj[s][t]=min(adj[s][t],1LL*cost[i]);
16      }
17
18       for(int k=0;k<26;k++){
19        for(int i=0;i<26;i++){
20            for(int j=0;j<26;j++){
21              if(adj[i][k]!=LLONG_MAX&&adj[k][j]!=LLONG_MAX)  adj[i][j]=min(adj[i][j],1LL*(adj[i][k]+adj[k][j]));
22            }
23        }
24       }
25
26
27       for(int i=0;i<source.length();i++){
28        if(source[i]==target[i])continue;
29
30        if(adj[source[i]-'a'][target[i]-'a']==LLONG_MAX)return -1;
31
32        ans+=adj[source[i]-'a'][target[i]-'a'];
33       }
34
35return ans;
36
37    }
38};