class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int val=nums[i];
            
            if(!dq.empty()&&i-k>=dq.front()){
                dq.pop_front();
            }

            while(!dq.empty()&&nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i+1>=k){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};