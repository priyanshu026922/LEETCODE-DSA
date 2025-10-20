class FindSumPairs {
public:
typedef long long ll;
vector<int>v1,v2;
unordered_map<ll,ll>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        v1.resize(n,0);
        v2.resize(m,0);
        v1=nums1;
        v2=nums2;
       for(int x:v2){
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index]+=val;
         mp[v2[index]]++;
    }
    
    int count(int tot) {
        ll c=0;
        // sort(begin(v1),end(v1));
        // for(int i=0;i<v2.size();i++){
        //  ll y=1LL*(tot-v2[i]);
        //     int j=lower_bound(begin(v1),end(v1),y)-begin(v1);
        //     if(j<v1.size()&&1LL*v1[j]==y){
        //         c+=mp[v1[j]];
        //     }
        // }
        for(int i=0;i<v1.size();i++){
             ll y=1LL*(tot-v1[i]);
              if(mp.find(y)!=mp.end()){
                c+=mp[y];
              }
        }
        return (int)c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */