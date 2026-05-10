1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4       int n=nums.size();
5       if(n==1)return nums[0];
6
7       if(nums[0]!=nums[1])return nums[0];
8       if(nums[n-1]!=nums[n-2])return nums[n-1];
9
10       int l=1;
11       int r=n-2;
12       while(l<=r){
13           int mid=l+(r-l)/2;
14
15           if((nums[mid]!=nums[mid-1])&&nums[mid]!=nums[mid+1]){
16                 return nums[mid];
17           }
18           
19           //EOEOEO.....
20           if(((mid%2==1)&&(nums[mid-1]==nums[mid]))||((mid%2==0)&&(nums[mid+1]==nums[mid]))){
21               l=mid+1;
22           }else{
23               r=mid-1;
24           }
25
26       }
27       return -1;
28    }
29};