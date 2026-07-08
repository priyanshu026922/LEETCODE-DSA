class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            if(j==0||(j>0&&nums[j]!=nums[j-1])){
                nums[i]=nums[j];
                cnt++;
                i++;
            }

            j++;
        }

        return cnt;
    }
};