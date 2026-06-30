1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4        if(s.length()!=t.length())return false;
5         
6        unordered_map<char,char>mp1;
7        unordered_map<char,char>mp2;
8        int n=s.length();
9        for(int i=0;i<n;i++){
10           if(mp1.find(s[i])==mp1.end()&&mp2.find(t[i])==mp2.end()){
11                mp1[s[i]]=t[i];
12                mp2[t[i]]=s[i];
13                // mp[t[i]]=s[i];
14
15           }
16           
17           //t[i]===s[i]====>>>BIND KRNA COMPULSORY HAI EEK DUSREA KE SATH
18           else if(mp1.find(s[i])!=mp1.end()||mp2.find(t[i])!=mp2.end()){
19                if(mp1[s[i]]!=t[i]||mp2[t[i]]!=s[i])return false;
20            }
21        }
22
23        return true;
24    }
25};