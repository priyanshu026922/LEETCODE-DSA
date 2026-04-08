1class Solution {
2public:
3    int mod=1e9+7;
4    typedef long long ll;
5    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
6        int n=nums.size();
7        
8        for(auto &it:queries){
9            ll l=it[0];
10            ll r=it[1];
11            ll k=it[2];
12            ll v=it[3];
13
14           ll ind=l;
15           while(ind<=r){
16               nums[ind]=(1LL*nums[ind]*v)%mod;
17               ind+=k;
18           }
19        }
20
21
22        ll x=nums[0];
23        for(int i=1;i<n;i++){
24            x=(x^nums[i]);
25        }
26        return x;
27
28    }
29};