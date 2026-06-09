1class Solution {
2public:
3    bool isPossibleDivide(vector<int>& nums, int k) {
4        int n=nums.size();
5        if(n%k!=0){
6            return false;
7        }
8
9        map<int,int>mp;
10        for(auto &it:nums){
11            mp[it]++;
12        }
13
14        while(!mp.empty()){
15            int curr=mp.begin()->first;
16
17            for(int i=0;i<k;i++){
18                if(mp.find(curr+i)==mp.end()){
19                    return false;
20                }
21
22                mp[curr+i]--;
23                if(mp[curr+i]==0){
24                    mp.erase(curr+i);
25                }
26            }
27        }
28        return true;
29    }
30};