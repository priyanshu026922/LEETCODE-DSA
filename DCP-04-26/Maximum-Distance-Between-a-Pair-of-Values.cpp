1class Solution {
2public:
3    int maxDistance(vector<int>& nums1,vector<int>& nums2) {
4        int n=nums1.size();
5        int m=nums2.size();
6
7        int maxi=INT_MIN;
8        reverse(begin(nums2),end(nums2));
9        for(int i=0;i<n;i++){
10            int val=nums1[i];
11            auto it=lower_bound(begin(nums2),end(nums2),val);
12            if(it!=nums2.end()){
13                int ind=it-nums2.begin();
14                int new_ind=m-ind-1;
15                if(new_ind>=i){
16                    maxi=max(maxi,new_ind-i);
17                }
18            }
19        }
20        return maxi==INT_MIN?0:maxi;
21    }
22};