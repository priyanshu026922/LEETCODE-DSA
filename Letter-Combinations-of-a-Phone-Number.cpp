1class Solution {
2private:
3   unordered_map<char,string >mp;    
4public:
5   void solve(int i,string digits,string s,vector<string>&ans){
6       if(i==digits.size()){
7        ans.push_back(s);
8        return;
9       }
10
11
12      for(auto &ch:mp[digits[i]]){
13        s+=ch;
14        solve(i+1,digits,s,ans);
15        s.pop_back();
16      }
17
18      
19   }
20    vector<string> letterCombinations(string digits) {
21     
22        mp['2']="abc";
23        mp['3']="def";
24        mp['4']="ghi";
25        mp['5']="jkl";
26        mp['6']="mno";
27        mp['7']="pqrs";
28        mp['8']="tuv";
29        mp['9']="wxyz";
30        vector<string>ans;
31        solve(0,digits,"",ans);
32        return ans;
33    }
34};