class Solution {
public:
    typedef long long ll;
    ll countStableSubarrays(vector<int>& capacity) {
        int n=capacity.size();
       map<ll,map<ll,ll>> mp;
        vector<ll>psum(n,0);
        psum[0]=capacity[0];
        ll count=0;
        
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+1LL*capacity[i];
        }
        for(int i=1;i<n;i++){
            ll need=psum[i]-2*capacity[i];
            count+=mp[need][capacity[i]];
            mp[psum[i-1]][capacity[i-1]]++;
        }
         












        // for(int i=1;i<n;i++){
        //      sum+=capacity[i];
                
        //     // if(mp.find(capacity[i])!=mp.end()){
                
        //     //     for(auto &p:mp[capacity[i]]){
        //     //              if(i-p.first>=2&&sum-p.second==2*capacity[i]){
        //     //            count++;
        //     //        }
        //     //     }
        //     // }
        //     // mp[capacity[i]].push_back({i,sum});
        // }
        return count;
    }
};