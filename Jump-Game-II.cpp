1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n=nums.size();
5        int l=0;
6        int r=0;
7        int ans=0;
8        while(r<n-1){
9            int far=0;
10            for(int i=l;i<=r;i++){
11                far=max(far,i+nums[i]);
12            }
13          
14            l=r+1;
15            r=far;
16            ans++;
17        }
18        return ans;
19    }
20};