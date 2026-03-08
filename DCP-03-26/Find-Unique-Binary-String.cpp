1class Solution {
2public:
3int n;
4    string solve(string s, unordered_set<string>&st){
5        if(s.length()==n){
6            if(st.count(s)==0){
7                return s;
8            }
9            return "";
10        }
11
12        string l=solve(s+'0',st);
13        if(l!=""){
14            return l;
15        }
16        return solve(s+'1',st);
17        
18    }
19    string findDifferentBinaryString(vector<string>& nums) {
20        n=nums.size();
21        unordered_set<string>s(begin(nums),end(nums));
22        return solve("",s);
23    }
24};