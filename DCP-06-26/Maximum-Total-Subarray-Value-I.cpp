1class Solution {
2public:
3    typedef long long ll;
4    ll maxTotalValue(vector<int>& nums, int k) {
5        int maxi=*max_element(begin(nums),end(nums));
6        int  mini=*min_element(begin(nums),end(nums));
7
8        ll val=1LL*maxi-1LL*mini;
9        val=val*k*1LL;
10        return val;
11    }
12};