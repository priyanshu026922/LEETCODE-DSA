class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
          int n=nums.size();
         int maxVal=*max_element(begin(nums),end(nums));
        //  vector<int>diff(maxVal+2,0);
      map<int,int>diff;
         unordered_map<int,int>freq;
         for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            int l=max(nums[i]-k,0);
            int r=min(nums[i]+k,maxVal);
            diff[l]++;
            diff[r+1]--;
            diff[nums[i]]+=0;
         }

         int res=1;
         int cumSum=0;
         for(auto it=diff.begin();it!=diff.end();it++){
            int tar=it->first;
            it->second+=cumSum;
            
            int x=freq[tar];
            int needConversion=it->second-x;
            int maxPos=min(numOperations,needConversion);
            res=max(res,x+maxPos);
            cumSum=it->second;
         }
         return res;
    }
};