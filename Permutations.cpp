1class Solution {
2public:
3    void solve(vector<int>& nums ,unordered_set<int>&s, string st,vector<vector<int>>&ans){
4
5      if(s.size()==nums.size()){
6            vector<int>a;
7            for(char it:st){
8                a.push_back(it+'0');
9            }
10            ans.push_back(a);
11            return;
12      }
13
14
15      for(int i=0;i<nums.size();i++){
16        int num=nums[i];
17        char ch=num-'0';
18        if(s.count(num)==0){
19            st+=ch;
20            s.insert(num);
21            solve(nums,s,st,ans);
22            st.pop_back();
23            s.erase(num);
24        }
25      }
26    }
27    vector<vector<int>> permute(vector<int>& nums) {
28         vector<vector<int>>ans;
29         unordered_set<int>s;
30         solve(nums,s,"",ans);
31         return ans;
32    }
33};