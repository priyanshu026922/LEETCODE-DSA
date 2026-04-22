1class Solution {
2public:
3    bool compare(string s, vector<string>&d){
4        
5        for(int i=0;i<d.size();i++){
6             int cnt=0;
7             string x=d[i];
8             for(int j=0;j<s.length();j++){
9                  if(x[j]!=s[j]){
10                    cnt++;
11                  }
12             }
13             if(cnt<=2)return true;
14        }
15        return false;
16    }
17    vector<string> twoEditWords(vector<string>& queries, vector<string>&d){
18         vector<string>ans;
19         for(auto &it:queries){
20            string s=it;
21            
22            bool cmp=compare(s,d);
23            if(cmp){
24                ans.push_back(s);
25            }
26         }
27         return ans;
28
29    }
30};