1class Solution {
2public:
3    void solve(int num,int n,int target,int k,vector<int>&a,vector<vector<int>>&ans){
4        if(a.size()==k){
5            if( target==0){
6                ans.push_back(a);
7                
8            }
9            return;
10        }
11
12        if(num==10){
13            if(a.size()==k){
14                if( target==0){
15                    ans.push_back(a);
16
17                }
18                return;
19            }
20            return;
21        }
22
23        for(int j=num;j<=9;j++){
24            if(j>target){
25                 break;
26            }
27
28            a.push_back(j);
29            solve(j+1,n,target-j,k,a,ans);
30            a.pop_back();
31        }
32    }
33    vector<vector<int>> combinationSum3(int k, int n) {
34        vector<vector<int>>ans;
35        vector<int>a;
36        solve(1,n,n,k,a,ans);
37        return ans;
38    }
39};