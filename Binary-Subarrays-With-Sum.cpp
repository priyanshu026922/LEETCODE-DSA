class Solution {
public:
int findVal(vector<int>& nums, int x,int n){
        int i=0;
        int j=0;
        int sum=0;
        int count=0;
        if(x<0)return 0;
        while(j<n){
            sum+=nums[j];
            while(sum>x){
                sum-=nums[i];
                i++;
            }
            count+=(j-i+1);
              j++;
        }
     return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //in such question where we have to find sum==x
        //pretty difficult to guess whether to expand or contract the window
        //so in such case we find-----(no of subarrays with [sum<=k]-no of subarrays with [sum<=k-1])---->required ans;
        int n=nums.size();
        int val=findVal(nums,goal,n)-findVal(nums,goal-1,n);
        return val;
    }
};