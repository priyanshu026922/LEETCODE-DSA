class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
         for(int i=1;i<n;i++){
              vector<int>a;
            for(int j=0;j<n-1;j++){
                   nums[j]=((nums[j]+nums[j+1])%10);
                 
            }
         }
         return nums[0];
    }
};