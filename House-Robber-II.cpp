1class Solution {
2    int n;
3    static const int size=102;
4    int dp[size];
5public:
6   int solve(int i,vector<int>&nums,int n){
7    if(i>=n)return 0;
8
9    //at any particular index there is 2 poissibilites ---->TAKE OR NOT TAKE::::--
10    if(dp[i]!=-1)return dp[i];
11
12    int nt=solve(i+1,nums,n);
13    int t=nums[i]+solve(i+2,nums,n);
14    
15     return dp[i]= max(nt,t);
16   }
17
18    int rob(vector<int>& nums) {
19        //wer are given nums array--which represnt amount in each of the house
20        n=nums.size();
21        //goal-->not to rob any adjacent houses----WHILE MAXIMISING OUR STEALING
22
23
24       //GREEDY SOLUTION WOULD FAIL IN THIS --AS example explained:[10,30,15,20,15,25,40]
25       //greedy gives us-----[80];
26
27       //not mentioninf dynamic programiing--->
28       //just if we try out all the possibility then it would :::::::max value would:::::[90]-->{30,20,40}------>not l adjacent
29       if(n==1)return nums[0];
30
31       memset(dp,-1,sizeof(dp));
32       int val1=solve(0,nums,n-1);
33       memset(dp,-1,sizeof(dp));
34       int val2=solve(1,nums,n);
35       return max(val1,val2);
36          //here passing value:::i-->represnting curr index;nums-->array itself
37    }
38};