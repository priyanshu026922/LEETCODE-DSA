class Solution {
public:
int findVal(vector<int>&nums,int x,int n){
    int i=0;
    int j=0;
    unordered_map<int,int>mp;
    int count=0;
    while(j<n){
        mp[nums[j]]++;
        
        while(mp.size()>x){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
       if(mp.size()<=x) count+=(j-i+1);
       j++;
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int val=findVal(nums,k,n)-findVal(nums,k-1,n);
        return val;
    }
};