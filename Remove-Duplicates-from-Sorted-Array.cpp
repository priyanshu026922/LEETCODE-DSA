1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        int n=nums.size();
5        int ind=0;
6        int cnt=0;
7        for(int i=0;i<n;i++){
8            if(i>0&&nums[i]==nums[i-1]){
9                continue;
10            }else{
11                nums[ind]=nums[i];
12                cnt++;
13                ind++;
14            }
15        }
16        return cnt++;
17    }
18};