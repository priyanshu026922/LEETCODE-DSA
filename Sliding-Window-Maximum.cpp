1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n=nums.size();
5        vector<int>ans;
6        deque<int>dq;
7        for(int i=0;i<n;i++){
8            if(!dq.empty()&&dq.front()<=i-k){
9                dq.pop_front();
10            }
11            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
12                dq.pop_back();
13            }
14
15
16
17            dq.push_back(i);
18            if(i>=k-1){
19                ans.push_back(nums[dq.front()]);
20            }
21        }
22        return ans;
23    }
24};