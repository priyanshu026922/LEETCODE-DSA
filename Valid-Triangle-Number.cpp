class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int count=0;
      unordered_map<int,int> mp;
for (int x : nums) mp[x]++; 

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]>nums[k]&&nums[i]+nums[k]>nums[j]&&nums[k]+nums[j]>nums[i]){
        //                 count++;
        //             }
        //         }
        //     }
        // // } 
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //           mp[nums[i]]--;
        //           mp[nums[j]]--;
        //           for(auto it:mp){
        //             if(it.second>0){
        //                 if(it.first>abs(nums[i]-nums[j])&&nums[i]+nums[j]>it.first){
        //                     count+=it.second;
        //                 }
        //             }
        //           }
        //           mp[nums[i]]++;
        //           mp[nums[j]]++;
        //     }
        // }
        sort(begin(nums),end(nums));
        for(int k=n-1;k>=2;k--){
            int i=0;
            int j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=(j-i);
                    j--;
                }else{
                    i++;
                }
            }
        }
        return count;
    }
};