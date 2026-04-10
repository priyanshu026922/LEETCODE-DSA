1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4         int n=nums.size();
5         unordered_map<int,int>mp1;
6         unordered_map<int,set<int>>mp2;
7
8         int ans=INT_MAX;
9         for(int i=0;i<n;i++){
10            mp1[nums[i]]++;
11            mp2[nums[i]].insert(i);
12             if(mp1[nums[i]]<3){
13                continue;
14            }else if(mp1[nums[i]]==3){
15                int val1=*mp2[nums[i]].rbegin();
16                int val2=*mp2[nums[i]].begin();
17                ans=min(ans,2*(val1-val2));
18            }else{
19                  int val=*mp2[nums[i]].begin();
20                  mp2[nums[i]].erase(val);
21                //   mp2[nums[i]].insert(i);
22                  int val1=*mp2[nums[i]].rbegin();
23                  int val2=*mp2[nums[i]].begin();
24                  ans=min(ans,2*(val1-val2));
25            }
26         }
27
28        if(ans==INT_MAX)return -1;
29        return ans;
30    }
31};