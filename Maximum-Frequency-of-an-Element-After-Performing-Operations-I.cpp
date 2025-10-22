class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
         int n=nums.size();
         int maxVal=*max_element(begin(nums),end(nums));
         vector<int>diff(maxVal+2,0);
         unordered_map<int,int>freq;
         for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            int l=max(nums[i]-k,0);
            int r=min(nums[i]+k,maxVal);
            diff[l]++;
            diff[r+1]--;

         }
         int res=1;
         for(int tar=0;tar<=maxVal;tar++){
            diff[tar]+=((tar>0)?diff[tar-1]:0);
            int x=freq[tar];
            int needConversion=diff[tar]-x;
            int maxPos=min(numOperations,needConversion);
            res=max(res,x+maxPos);
         }
         return res;
    }
};