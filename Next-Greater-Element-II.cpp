1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>nge(n);
6
7        stack<int>s;
8
9        for(int i=2*n-1;i>=0;i--){
10             int val=nums[i%n];
11             while(!s.empty()&& val>=s.top()){
12                s.pop();
13             }
14             if(s.empty()){
15                nge[i%n]=-1;
16             }else{
17                nge[i%n]=s.top();
18             }
19             s.push(val);
20        }
21        return nge;
22    }
23};