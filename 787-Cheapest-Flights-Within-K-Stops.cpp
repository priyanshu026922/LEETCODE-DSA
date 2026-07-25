class Solution {
public:
    typedef pair<int,pair<int,int>>piii;
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k) {
        vector<vector<pair<int,int>>>adj(n);
          for(auto it:flights){
            int x=it[0];
            int y=it[1];
            int wt=it[2];
            adj[x].push_back({y,wt});
          }

          vector<int>dis(n,1e9);
          dis[src]=0;
          queue<piii>pq;
          pq.push({0,{0,src}});
          while(!pq.empty()){
              int stop=pq.front().first;
              int wt=pq.front().second.first;
              int u=pq.front().second.second;
              pq.pop();
              if(stop>k)continue;
              for(auto it:adj[u]){
                int neighbour=it.first;
                int w=it.second;
                if(wt+w<dis[neighbour]){
                    dis[neighbour]=wt+w;
                    pq.push({stop+1,{dis[neighbour],neighbour}});
                }
              }
          }


          if(dis[dst]==1e9)return -1;
          return dis[dst];
    }
};