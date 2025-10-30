class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        long long count=0;
        int prev=0;
        int curr=0;

        for(int i=0;i<n;i++){
          curr=target[i]-nums[i];//we have the differnce of both equal to zero-----such that nums==target

          if((curr>0&&prev<0)||(curr<0&&prev>0)){
             count+=abs(curr);
          }
          else if(abs(curr)>abs(prev)){
            count+=abs(curr-prev);
          }
          
          prev=curr;
        }
        return count;
    }
};