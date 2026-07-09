class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int val=sum-k;
            if(mp.find(val)!=mp.end()){
                cnt+=mp[val];
            }


            mp[sum]++;
        }

        return cnt;
    }
};