1class Solution {
2private:
3int n;
4public:
5
6   bool solve(string &s,int ind,string &x,unordered_map<string,int >&st,vector<string>&ans){
7
8       if(ind==s.length()){
9          x.pop_back();
10          ans.push_back(x);
11          x="";
12           return true;
13       }
14
15       for(int i=ind;i<n;i++){
16        string u=x;
17            string t=s.substr(ind,i-ind+1);
18            if(st.count(t)>0){
19                x+=t;
20                x+=' ';
21                 solve(s,i+1,x,st,ans);
22                   x=u;
23                
24            }
25        }
26        
27        return false;
28    }
29    vector<string> wordBreak(string s, vector<string>& wordDict) {
30        n=s.length();   
31        unordered_map<string,int >mp;
32        for(auto &it:wordDict){
33            mp[it]=1;
34        }
35
36        string x="";
37        vector<string>ans;
38
39        solve(s,0,x,mp,ans);
40        return ans;
41    }
42};