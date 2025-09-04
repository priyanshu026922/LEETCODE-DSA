class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        sort(begin(nums),end(nums));
        for(int i=1;i<nums.size();i+=3){
            if(nums[i]==nums[i-1]&&nums[i]==nums[i+1]){
                continue;
            }
                if(nums[i]!=nums[i-1]){
                    ans=nums[i-1];
                    break;
                }
                
        }
        if(ans==-1)return nums[n-1];
        return ans;
    }
};