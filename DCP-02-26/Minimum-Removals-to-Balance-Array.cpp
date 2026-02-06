1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4         int n=nums.size();
5         long long maxi=LLONG_MIN;
6         sort(begin(nums),end(nums));
7         int j=0;
8         for(int i=0;i<n;i++){
9            while(j+1<n&&1LL*nums[j+1]<=k*1LL*nums[i]){
10                j++;
11            }
12            maxi=max(maxi,1LL*(j-i+1));
13         }
14         
15         return n-(int)maxi;
16    }
17};