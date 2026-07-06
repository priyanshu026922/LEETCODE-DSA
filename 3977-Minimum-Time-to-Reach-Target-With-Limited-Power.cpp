class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> pp;
    typedef pair<ll,pp> ppp;

    pp solve( vector<vector<pp>>&adj,int n,int power,vector<int>&cost,int &source,int &target){
           
          vector<vector<ll>>dis(n+1,vector<ll>(power+1,LLONG_MAX));

           priority_queue<ppp,vector<ppp>,greater<ppp>>pq;

           dis[source][power]=0;
           pq.push({0,{power,source}});
           ll remain=0;
           ll min_time=LLONG_MAX;

           while(!pq.empty()){
               auto it=pq.top();
               pq.pop();

               ll wt=it.first;
               int Node=it.second.second;
               ll p=it.second.first;
            
               if(Node==target){
                    if(dis[Node][p]<=min_time){
                        remain=max(remain,1LL*p);
                        min_time=dis[Node][p];
                    }
                }


               if(p-1LL*cost[Node]<0){
                    continue;
                }

               ll val=p-1LL*cost[Node];

               for(auto &it:adj[Node]){
                 int node=it.first;
                 ll w=it.second;

                
                 if(w+wt<dis[node][val]){
                    dis[node][val]=w+wt;
                    pq.push({dis[node][val],{val,node}});
                    
                 }
               }
           }




           if(min_time==LLONG_MAX)return {-1,-1};

           return {min_time,remain};

    }
    vector<ll> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {

            vector<vector<pp>>adj(n);

            for(auto &it:edges){
                int u=it[0];
                int v=it[1];
                ll w=it[2];

                adj[u].push_back({v,w});
            }

            pp val=solve(adj,n,power,cost,source,target);

            if(val.first==-1){
                return {-1,-1};
            }
           
        return {val.first,val.second};
    }
};