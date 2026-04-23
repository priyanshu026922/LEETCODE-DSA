1class Solution {
2public:
3typedef long long ll;
4    vector<ll> distance(vector<int>& nums) {
5        int n=nums.size();
6        unordered_map<int, vector<int>> mp;
7
8        for(int i=0;i<n;i++)mp[nums[i]].push_back(i);
9
10vector<ll>ans(n);
11        //for pref
12       for(auto &it:mp){
13        auto &pos=it.second;
14        ll sum=0;
15        for(int x:pos){
16            sum+=x;
17        }
18        ll lsum=0;
19        int m=pos.size();
20            for(int i=0;i<m;i++){
21                ll rightSum = sum - lsum - pos[i];
22
23                ll left  = 1LL * pos[i] * i - lsum;
24                ll right = rightSum - 1LL * pos[i] * (m-i-1);
25
26                ans[pos[i]] = left + right;
27
28                lsum+= pos[i];
29            }
30       }
31        return ans;
32
33    }
34};