1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        vector<pair<int,int>>vec;
5
6        for(int i=0;i<nums.size();i++){
7            vec.push_back({nums[i],i});
8        }
9        sort(begin(vec),end(vec));
10
11        int l=0;
12        int r=nums.size()-1;
13        while(l<r){
14            if(vec[l].first+vec[r].first==target){
15                return {vec[l].second,vec[r].second};
16            }else if(vec[l].first+vec[r].first<target){
17                   l++;
18            }else{
19                r--;
20            }
21        }
22        return {-1,-1};
23    }
24};