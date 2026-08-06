class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //firstl we can try 
        int n=nums.size();
        // int len=n+1;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];

        //         if(sum>=target){
        //            len=min(len,j-i+1);
        //         }
        //     }
        // }

        // if(len==n+1)return 0;
        // return len;
        
        //sum>=target
        int i=0;
        int j=0;
        int sum=0;
        int len=n+1;
        while(j<n){
            sum+=nums[j];

            while(i<n&&sum>=target){
                len=min(len,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(len==n+1)return 0;

        return len;
    }
};