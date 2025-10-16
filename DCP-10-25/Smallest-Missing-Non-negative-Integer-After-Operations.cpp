class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        
      unordered_map<long long,long long >mp;
      for(int i=0;i<n;i++){
        // if(nums[i]>0){
        //     s.insert(nums[i]%value);
        // }else{
        //     s.insert(((nums[i]%value)+value)%value);
        // }
        long long x=(((nums[i]%value)+value)%value);
        mp[x]++;
      }
      long long mex=0;
    //   while(s.count(mex)>0){
    //      mex++;
    //   }
    while(mp.find(mex%value)!=mp.end()){
     
        mp[mex%value]--;
        if(mp[mex%value]==0)mp.erase(mex%value);
           mex++;
    }
      return (int)mex;

    }
};