1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n=s.length();
5        int i=0;
6        int j=0;
7        int cnt=0;
8       unordered_map<char,int>mp;
9        while(j<n){
10            mp[s[j]]++;
11
12            while(i<n&&mp.size()==3){
13                 cnt+=(n-j);
14                 mp[s[i]]--;
15                 if(mp[s[i]]==0){
16                    mp.erase(s[i]);
17                 }
18                 i++;
19            }
20            j++;
21        }
22        return cnt;
23    }
24};