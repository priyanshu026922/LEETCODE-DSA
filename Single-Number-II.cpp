class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int bit=31;bit>=0;bit--){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]&(1<<bit)){
                    count++;
                }
            }
            if(count%3!=0){
                ans=ans|(1<<bit);
            }
        }
        return ans;
    }
};