1class Solution {
2public:
3bool isInc(vector<int>&nums){
4    int n=nums.size();
5    for(int i=1;i<n;i++){
6        if(nums[i]<nums[i-1])return  false;
7    }
8    return true;
9}
10    int minimumPairRemoval(vector<int>& nums) {
11        int op=0;
12        while(!isInc(nums)){
13            int mini_i=-1;
14            int miniSum=INT_MAX;
15            for(int i=0;i<nums.size()-1;i++){
16                int sum=nums[i]+nums[i+1];
17                if(sum<miniSum){
18                miniSum=sum;
19                mini_i=i;
20            }
21            }
22
23            int val=nums[mini_i]+nums[mini_i+1];
24            nums.erase(begin(nums)+mini_i);
25            nums[mini_i]=val;
26            op++;
27        }
28        return op;
29    }
30
31};