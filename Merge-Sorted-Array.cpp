1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4       int i=m+n-1;
5       int l=m-1;
6       int r=n-1;
7       while(l>=0&&r>=0){
8         if(nums1[l]<=nums2[r]){
9            nums1[i]=nums2[r];
10            r--;
11         }else{
12            nums1[i]=nums1[l];
13            l--;
14         }
15         i--;
16       }
17
18      while(r>=0){
19        nums1[i]=nums2[r];
20        r--;
21        i--;
22      }
23    }
24};