1class Solution {
2public:
3    typedef pair<int,int> p;
4    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
5        vector<vector<int>>ans;
6        int n=nums2.size();
7        priority_queue<p,vector<p>,greater<p>>pq;
8        int val=nums2[0];
9        for(int i=0;i<nums1.size();i++){
10           pq.push({val+nums1[i],0});
11        }
12
13
14        while(!pq.empty()&&k>0){
15            vector<int>a;
16            auto it=pq.top();
17            int ind=it.second;
18            int val=it.first;
19            pq.pop();
20             a.push_back(val-nums2[ind]);
21             a.push_back(nums2[ind]);
22
23            if(ind+1<n){
24                pq.push({val-nums2[ind]+nums2[ind+1],ind+1});
25            }
26
27
28             ans.push_back(a);
29            k--;
30        }
31
32        return ans;
33    }
34};