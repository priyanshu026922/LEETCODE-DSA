1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int n=nums.size();
5        int maxi=0;
6        int cnt=0;
7        for(int i=0;i<n;i++){
8            if(nums[i]==1){
9                cnt++;
10            }else{
11                maxi=max(maxi,cnt);
12                cnt=0;
13            }
14        }
15
16        maxi=max(maxi,cnt);
17        return maxi;
18    }
19};