1class Solution {
2public:
3    // int revNum(int num){
4    //     // int x=0;
5    //     // while(num>0){
6    //     //     int val=num%10;
7    //     //     x=x*10+val;
8
9    //     //     num/=10;
10    //     // }
11    //     // cout<<x<<" ";
12    //     // return x;
13    // }
14
15    // void getDigit(int num,  vector<int>&ans){
16    //     while(num>0){
17    //         int val=num%10;
18    //         ans.push_back(val);
19    //         num/=10;
20    //     }
21    // }
22    vector<int> separateDigits(vector<int>& nums) {
23        int n=nums.size();
24        vector<int>ans;
25        for(auto &it:nums){
26            string val=to_string(it);
27            // reverse(begin(val),end(val));
28
29            
30            for(auto &itt:val){
31                ans.push_back(itt-'0');
32            }
33
34        }
35
36        return ans;
37
38    }
39};