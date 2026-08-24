class Solution {
public:
    vector<int>getfact(int val){
        vector<int>ans;
          for(int j=2;j*j<=val;j++){
                if(val%j==0){
                  ans.push_back(j);
                    while(val%j==0){
                      val/=j;
                    }
                }
            }

        if(val>1)ans.push_back(val);
        return ans;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxi=0;

        while(j<n){
             vector<int>fact=getfact(nums[j]);
             for(auto &it:fact){
                mp[it]++;
             }
             
            while(i<=j&&mp.size()>k){
                vector<int>fact=getfact(nums[i]);
                for(auto &it:fact){
                    mp[it]--;
                    if(mp[it]==0)mp.erase(it);
                }
                i++;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }
      
        return maxi;
    }
};