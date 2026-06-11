1class Solution {
2public:
3int n;
4    void solve(vector<int>&c,int i,int target,vector<int>&a,  vector<vector<int>>&ans){
5
6        if(target==0){
7            ans.push_back(a);
8            return;
9        }
10       if(i==n){
11          if(target==0){
12            ans.push_back(a);
13          }
14          return;
15       }
16
17       if(target<0){
18    return;
19       }
20
21
22        if(target>=c[i]){
23            a.push_back(c[i]);
24            target-=c[i];
25            solve(c,i,target,a,ans);
26            target+=c[i];
27
28            a.pop_back();
29        }
30
31        solve(c,i+1,target,a,ans);
32
33
34    }
35
36    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
37        vector<vector<int>>ans;
38        vector<int>a;
39        n=candidates.size();
40        solve(candidates,0,target,a,ans);
41        return ans;
42    }
43};