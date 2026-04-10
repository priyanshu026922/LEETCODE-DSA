1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4         int n=nums.size();
5         unordered_map<int,set<int>>mp2;
6
7         int ans=INT_MAX;
8         for(int i=0;i<n;i++){
9
10             mp2[nums[i]].insert(i);
11             if(mp2[nums[i]].size()<3)continue;
12
13             if(mp2[nums[i]].size()>3){
14                  int val=*mp2[nums[i]].begin();
15                  mp2[nums[i]].erase(val);
16            }
17
18                int val1=*mp2[nums[i]].rbegin();
19                int val2=*mp2[nums[i]].begin();
20                ans=min(ans,2*(val1-val2));
21         }
22
23        if(ans==INT_MAX)return -1;
24        return ans;
25    }
26};