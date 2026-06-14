1class Solution {
2private:
3int n;
4public:
5vector<int>dp;
6    bool solve(string &s,int ind,string &x,unordered_map<string,int>&st){
7
8       if(ind==s.length()){
9           return st.find(x)!=st.end();
10       }
11       
12       if(dp[ind]!=-1)return dp[ind];
13
14
15       for(int i=ind;i<n;i++){
16            x=s.substr(ind,i-ind+1);
17            if(st.count(x)>0){
18                
19                 if(solve(s,i+1,x,st)){
20                    return dp[ind]=true;
21                 }
22            }
23        }
24        return dp[ind]=false;
25    }
26
27    bool wordBreak(string &s, vector<string>& wordDict) {
28        n=s.length();
29        //here we need to check for segmentrs througgtout
30     dp.assign(n,-1);
31     unordered_map<string,int>st;
32      for(auto &it:wordDict){
33        st[it]=1;
34      }
35
36         string x="";
37        return solve(s,0,x,st);
38    }
39};