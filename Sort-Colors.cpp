1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int n=nums.size();
5        int l=0,mid=0,h=n-1;
6        while(mid<=h){
7            if(nums[mid]==0){
8                swap(nums[l],nums[mid]);
9                l++;
10                mid++;
11            }else if(nums[mid]==1){
12                mid++;
13            }else{
14                swap(nums[mid],nums[h]);
15                h--;
16            }
17        }
18    }
19};