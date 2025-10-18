class Solution {
public:
typedef long long ll;
    int maxDistinctElements(vector<int>& nums, int k) {
        ll n=nums.size();
        sort(begin(nums),end(nums));
        // ll x=nums[0]-k;
            // unordered_set<ll>s;
        //     s.insert(x);
        // for(int i=1;i<n;i++){
        //     if(s.count(nums[i]-k)>0){
        //          x++;

        //          if(x>=nums[i]-k&&x<=nums[i]+k) s.insert(x);
        //          else x=nums[i]+k;

        //     }else{//not present in set
        //         if(x+1>=nums[i]-k&&x+1<=nums[i]+k){
        //             x++;
        //             if(x<=nums[i]+k)  s.insert(x);
        //         }
        //         else {
        //             s.insert(nums[i]-k);
        //             x=nums[i]-k;
        //         }
        //     }

        // }
        ll ans=0;
        ll prev=LLONG_MIN;
        for(int i=0;i<n;i++){
            ll l=max(prev+1,1LL*(nums[i]-k));
            if(l<=nums[i]+k){
                prev=l;
                ans++;
            }
        }
        return (int)ans;
    }
};
