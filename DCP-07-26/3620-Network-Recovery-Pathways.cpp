class Solution {
public:
    typedef long long ll;
    int n;
    bool isPos(vector<vector<pair<int,ll>>>&adj,ll mid,ll k){
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,0});
        vector<ll>dis(n,LLONG_MAX);
        dis[0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
             
            ll wt=it.first;
            int node=it.second;

            if(wt>k){
                return false;
            }

            if(node==n-1)return true;
            
            if(dis[node]<wt)continue;

            for(auto &itt:adj[node]){
                int NODE=itt.first;
                ll w=itt.second;

                if(w<mid){
                    continue;
                }

                if(w+wt<dis[NODE]){
                   dis[NODE]=w+wt;
                   pq.push({dis[NODE],NODE});
                }


            }

        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,ll k){
        //---->all the intermediate nodes on the path are ONLINE
        //---->total recovery cost of all edges on the path does not excees K

        //find maximum minimum path score
        ll l=LLONG_MAX;
        ll r=LLONG_MIN;

         n=online.size();
        vector<vector<pair<int,ll>>>adj(n);
        for(auto &it:edges){
            int x=it[0];
            int y=it[1];
            
            ll wt=it[2];
            if(!online[x]||!online[y])continue;
            

            l=min(l,wt);
            r=max(r,wt);
            adj[x].push_back({y,wt});
        }

         
         ll maxi=-1;
         while(l<=r){
            ll mid=l+(r-l)/2;

            if(isPos(adj,mid,k)){
                 maxi=mid;
                 l=mid+1;
            }else{
                r=mid-1;
            }
         }
         return (int)maxi;

         
        

    }
};