class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k)return false;
        for(int i=0;i<=n-2*k;i++){
            bool ispos1=true;
            for(int j=i;j<i+k-1;j++){
                   if(nums[j]>=nums[j+1]){
                    ispos1=false;
                    break;
                   }
            }
            bool ispos2=true;
            for(int j=i+k;j<i+2*k-1;j++){
                   if(nums[j]>=nums[j+1]){
                    ispos2=false;
                    break;
                   }
            }
            if(ispos1&&ispos2)return true;
        }
        return false;
    }
};