class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(begin(nums),end(nums));
        int mini=nums[0];
        int maxi=nums[n-1];
        int val=mini;
        for(int i=1;i<n;i++){
            val++;
               while(nums[i]!=val){
                 ans.push_back(val);
                 val++;
               }
        }
        return ans;
    }
};