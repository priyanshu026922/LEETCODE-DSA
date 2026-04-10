1class Solution {
2public:
3int mod=1e9+7;
4typedef long long ll;
5
6    ll power(ll a,ll b){
7        if(b==0)return 1;
8
9        ll half=power(a,b/2);
10        ll res=(half*half)%mod;
11        if(b%2==1){
12            res=(res*a)%mod;
13        }
14        return res;
15    }
16
17    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
18         int n=nums.size();
19         int blockSize=ceil(sqrt(n));
20         unordered_map<int,vector<vector<int>>>mp;
21         for(auto it:queries){
22            int l=it[0];
23            int r=it[1];
24            int k=it[2];
25            int v=it[3];
26            
27            if(k>=blockSize){
28                for(int i=l;i<=r;i+=k){
29                    nums[i]=(1LL*nums[i]*v)%mod;
30                }
31            }else{
32                mp[k].push_back(it);
33            }
34         }
35
36         for(auto &[k,vec]:mp){
37            vector<ll>diff(n,1);
38            for(auto &query:vec){
39                int l=query[0];
40                int r=query[1];
41                int v=query[3];
42
43                diff[l]=(diff[l]*v)%mod;
44                int step=(r-l)/k;
45                int nxt=l+(step+1)*k;
46                if(nxt<n){
47                    diff[nxt]=(diff[nxt]*power(v,mod-2))%mod;//(diff[nxt]/v)%mod
48                }
49
50                
51                
52            }
53            for(int i=0;i<n;i++){
54                    if(i-k>=0)diff[i]=(diff[i]*diff[i-k])%mod;
55                }
56                for(int i=0;i<n;i++){
57                    nums[i]=(1LL*nums[i]*diff[i])%mod;
58                }
59         }
60
61         int res=0;
62         for(int i=0;i<n;i++){
63            res=(res^nums[i]);
64         }
65         return res;
66    }
67};