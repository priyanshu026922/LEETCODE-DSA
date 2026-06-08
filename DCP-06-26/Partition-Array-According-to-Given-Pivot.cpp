1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        int n=nums.size();
5        vector<int>ans(n);
6        int i=0;
7        int j=n-1;
8        int l=0;
9        int m=n-1;
10        while(i<n&&j>=0){
11            if(nums[i]<pivot){
12                ans[l]=nums[i];
13                l++;
14            }
15            if(nums[j]>pivot){
16                ans[m]=nums[j];
17                m--;
18            }
19
20            i++;
21            j--;
22        }
23        while(l<=m){
24            ans[l]=pivot;
25            l++;
26        }
27
28        return ans;
29    }
30};