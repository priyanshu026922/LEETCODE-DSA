class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;


        while(l<n) {
           if(nums[l]!=0){
            swap(nums[l],nums[r]);
            r++;
           }

           l++;
        }

      

        
    }
};