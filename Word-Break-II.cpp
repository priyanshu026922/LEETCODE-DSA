1class Solution {
2private:
3int n;
4public:
5
6   void solve(string &s,int ind,string &x,unordered_map<string,int >&st,vector<string>&ans){
7
8       if(ind==s.length()){
9
10          x.pop_back();
11          ans.push_back(x);
12          x="";
13           return ;
14       }
15
16
17       for(int i=ind;i<n;i++){
18            string u=x;
19            string t=s.substr(ind,i-ind+1);
20            if(st.count(t)>0){
21                x+=t;
22                 x+=' ';
23                 solve(s,i+1,x,st,ans);
24                   x=u;
25                
26            }
27        }
28        
29        return ;
30    }
31    vector<string> wordBreak(string s, vector<string>& wordDict) {
32        n=s.length();   
33        unordered_map<string,int >mp;
34        for(auto &it:wordDict){
35            mp[it]=1;
36        }
37
38
39        string x="";
40        vector<string>ans;
41
42        solve(s,0,x,mp,ans);
43        return ans;
44    }
45};