1class Solution {
2public:
3    int longestBalanced(vector<int>& nums) {
4        int n=nums.size();
5        int ans=0;
6        for(int i=0;i<n;i++){
7             unordered_set<int>cntO;
8             unordered_set<int>cntE;
9            for(int j=i;j<n;j++){
10                if(nums[j]%2!=0){
11                    cntO.insert(nums[j]);
12                }else{
13                    cntE.insert(nums[j]);
14                }
15                if(cntO.size()==cntE.size())ans=max(ans,j-i+1);
16            }
17        }
18        return ans;
19    }
20};