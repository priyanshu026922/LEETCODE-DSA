1class Solution {
2public:
3    typedef long long ll;
4    ll countSubarrays(vector<int>& nums, ll k) {
5        int n=nums.size();
6         ll ans=0;
7        deque<int>maxi,mini;
8        int i=0;
9        for(int j=0;j<n;j++){
10            while(!maxi.empty()&&nums[maxi.back()]<=nums[j])maxi.pop_back();
11            maxi.push_back(j);
12
13            while(!mini.empty()&&nums[mini.back()]>=nums[j])mini.pop_back();
14            mini.push_back(j);
15
16
17            while(1LL*(nums[maxi.front()]-nums[mini.front()])*(j-i+1)>k){
18                if(maxi.front()==i)maxi.pop_front();
19                if(mini.front()==i)mini.pop_front();
20                i++;
21            }
22            ans+=(j-i+1);
23        }
24        return ans;
25    }
26};